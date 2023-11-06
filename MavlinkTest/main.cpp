// Simple example receiving and sending MAVLink v2 over UDP
// based on POSIX APIs (e.g. Linux, BSD, macOS).

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <time.h>


//#include "c_library_v2-master/common/mavlink.h"
#include "c_library_v2-master/ardupilotmega/mavlink.h"


void receive_some(int socket_fd, struct sockaddr_in* src_addr, socklen_t* src_addr_len, bool* src_addr_set);
void handle_heartbeat(const mavlink_message_t* message);

void send_some(int socket_fd, const struct sockaddr_in* src_addr, socklen_t src_addr_len);
void send_heartbeat(int socket_fd, const struct sockaddr_in* src_addr, socklen_t src_addr_len);
void testSend(int socket_fd, const struct sockaddr_in* src_addr, socklen_t src_addr_len);

void Mav_Request_Data(int socket_fd, const struct sockaddr_in* src_addr, socklen_t src_addr_len);

int main(int argc, char* argv[])
{
    // Open UDP socket
    const int socket_fd = socket(PF_INET, SOCK_DGRAM, 0);

    if (socket_fd < 0) {
        printf("socket error: %s\n", strerror(errno));
        return -1;
    }

    // Bind to port
    struct sockaddr_in addr = {};
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    inet_pton(AF_INET, "0.0.0.0", &(addr.sin_addr)); // listen on all network interfaces
    addr.sin_port = htons(14550); // default port on the ground

    if (bind(socket_fd, (struct sockaddr*)(&addr), sizeof(addr)) != 0) {
        printf("bind error: %s\n", strerror(errno));
        return -2;
    }

    // We set a timeout at 100ms to prevent being stuck in recvfrom for too
    // long and missing our chance to send some stuff.
    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 100000;
    if (setsockopt(socket_fd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
        printf("setsockopt error: %s\n", strerror(errno));
        return -3;
    }

    struct sockaddr_in src_addr = {};
    socklen_t src_addr_len = sizeof(src_addr);
    bool src_addr_set = false;

    Mav_Request_Data(socket_fd, &src_addr, src_addr_len);

    while (true) {
        // For illustration purposes we don't bother with threads or async here
        // and just interleave receiving and sending.
        // This only works  if receive_some returns every now and then.
        receive_some(socket_fd, &src_addr, &src_addr_len, &src_addr_set);

        if (src_addr_set) {
            send_some(socket_fd, &src_addr, src_addr_len);
        }
    }

    return 0;
}

void receive_some(int socket_fd, struct sockaddr_in* src_addr, socklen_t* src_addr_len, bool* src_addr_set)
{
    // We just receive one UDP datagram and then return again.
    char buffer[2048]; // enough for MTU 1500 bytes

    const int ret = recvfrom(
            socket_fd, buffer, sizeof(buffer), 0, (struct sockaddr*)(src_addr), src_addr_len);

    if (ret < 0) {
       // printf("recvfrom error: %s\n", strerror(errno));
    } else if (ret == 0) {
        // peer has done an orderly shutdown
        return;
    }

    *src_addr_set = true;

    mavlink_message_t message;
    mavlink_status_t status;
    for (int i = 0; i < ret; ++i) {
        if (mavlink_parse_char(MAVLINK_COMM_0, buffer[i], &message, &status) == 1) {

            // printf(
             //    "Received message %d from %d/%d\n",
               //  message.msgid, message.sysid, message.compid);

            switch (message.msgid) {
                case MAVLINK_MSG_ID_HEARTBEAT:
                    handle_heartbeat(&message);
                    break;

                case MAVLINK_MSG_ID_VFR_HUD: {
                    mavlink_altitude_t alt_struct;
                    mavlink_msg_altitude_decode(&message, &alt_struct);
                    //printf("Altitude over Home is: %f \n",alt_struct.altitude_amsl);
                    break;
                }

                case MAVLINK_MSG_ID_ATTITUDE: {  // #30

                    /* Message decoding: PRIMITIVE
                     *    mavlink_msg_attitude_decode(const mavlink_message_t* msg, mavlink_attitude_t* attitude)
                     */
                    mavlink_attitude_t attitude;
                    mavlink_msg_attitude_decode(&message, &attitude);
                    printf("Roll is: %f \n", (attitude.roll*(180.0/3.141592653589793238463)));
                    break;
                }
            }
        }
    }
}

void handle_heartbeat(const mavlink_message_t* message)
{
    mavlink_heartbeat_t heartbeat;
    mavlink_msg_heartbeat_decode(message, &heartbeat);

    printf("Got heartbeat from ");
    switch (heartbeat.autopilot) {
        case MAV_AUTOPILOT_GENERIC:
            printf("generic");
            break;
        case MAV_AUTOPILOT_ARDUPILOTMEGA:
            printf("ArduPilot");
            break;
        case MAV_AUTOPILOT_PX4:
            printf("PX4");
            break;
        default:
            printf("other");
            break;
    }
    printf(" \n");
}

void send_some(int socket_fd, const struct sockaddr_in* src_addr, socklen_t src_addr_len)
{
    // Whenever a second has passed, we send a heartbeat.
    static time_t last_time = 0;
    static int time_custom = 4;
    time_t current_time = time(NULL);
    if (current_time - last_time >= 1) {
        send_heartbeat(socket_fd, src_addr, src_addr_len);
        last_time = current_time;
        time_custom = time_custom+1;
    }

    if(time_custom == 5){
        time_custom = 0;
        testSend(socket_fd, src_addr, src_addr_len);
    }

}

void send_heartbeat(int socket_fd, const struct sockaddr_in* src_addr, socklen_t src_addr_len)
{
    
    mavlink_message_t message;

    const uint8_t system_id = 42;
    const uint8_t base_mode = 0;
    const uint8_t custom_mode = 0;
    mavlink_msg_heartbeat_pack_chan(
            system_id,
            MAV_COMP_ID_PERIPHERAL,
            MAVLINK_COMM_0,
            &message,
            MAV_TYPE_GENERIC,
            MAV_AUTOPILOT_GENERIC,
            base_mode,
            custom_mode,
            MAV_STATE_STANDBY);

    uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
    const int len = mavlink_msg_to_send_buffer(buffer, &message);

    int ret = sendto(socket_fd, buffer, len, 0, (const struct sockaddr*)src_addr, src_addr_len);
    if (ret != len) {
       // printf("sendto error: %s\n", strerror(errno));
    } else {
        //printf("Sent heartbeat\n");
    }
}

void testSend(int socket_fd, const struct sockaddr_in* src_addr, socklen_t src_addr_len){
    mavlink_message_t message;

    const uint8_t system_id = 42;
    const uint8_t base_mode = 0;
    const uint8_t custom_mode = 0;

    //mavlink_msg_command_long_pack(system_id,MAV_COMP_ID_PERIPHERAL,&message,1,0,30,0,2,0,0,0,0,0,10);
    //mavlink_msg_command_int_pack(system_id,MAV_COMP_ID_PERIPHERAL,&message,1,0,0,30,0,0,0,0,0,0,0,0,10);
//    mavlink_msg_command_int_pack(system_id
//                                 ,0,
//                                 &message,
//                                 1, // target system
//                                 0, // target component
//                                 0, // frames
//                                 MAV_CMD_NAV_LOITER_UNLIM , // command
//                                 0, // nothing
//                                 0, // nothing
//                                 0, // par 1
//                                 0, // par 2
//                                 100, // par 3
//                                 10, // par 4
//                                 -35, // par x
//                                 149,  // par y
//                                 2000);// par z

    mavlink_msg_command_long_pack(system_id
    ,0,
            &message,
            1, // target system
            0, // target component
            MAV_CMD_NAV_LOITER_UNLIM , // command
            0, // nothing
            0, // par 1
            0, // par 2
            100, // par 3
            10, // par 4
            -35.3625667, // par x
            149.1647868,  // par y
            500.0);// par z


    uint8_t buffer[MAVLINK_MAX_PACKET_LEN];

    const int len = mavlink_msg_to_send_buffer(buffer, &message);

    int ret = sendto(socket_fd, buffer, len, 0, (const struct sockaddr*)src_addr, src_addr_len);
    //printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n");
    if (ret != len) {
        //printf(" CUSTOM sendto error: %s\n", strerror(errno));
    } else {
        //printf("CUSTOM Sent\n");
    }
    //printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n");
    //mavlink_msg_data_stream_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
        //                                                uint8_t stream_id, uint16_t message_rate, uint8_t on_off)

}

void Mav_Request_Data(int socket_fd, const struct sockaddr_in* src_addr, socklen_t src_addr_len)
{
    mavlink_message_t msg;
    uint8_t buf[MAVLINK_MAX_PACKET_LEN];

    // STREAMS that can be requested
    /*
     * Definitions are in common.h: enum MAV_DATA_STREAM
     *
     * MAV_DATA_STREAM_ALL=0, // Enable all data streams
     * MAV_DATA_STREAM_RAW_SENSORS=1, /* Enable IMU_RAW, GPS_RAW, GPS_STATUS packets.
     * MAV_DATA_STREAM_EXTENDED_STATUS=2, /* Enable GPS_STATUS, CONTROL_STATUS, AUX_STATUS
     * MAV_DATA_STREAM_RC_CHANNELS=3, /* Enable RC_CHANNELS_SCALED, RC_CHANNELS_RAW, SERVO_OUTPUT_RAW
     * MAV_DATA_STREAM_RAW_CONTROLLER=4, /* Enable ATTITUDE_CONTROLLER_OUTPUT, POSITION_CONTROLLER_OUTPUT, NAV_CONTROLLER_OUTPUT.
     * MAV_DATA_STREAM_POSITION=6, /* Enable LOCAL_POSITION, GLOBAL_POSITION/GLOBAL_POSITION_INT messages.
     * MAV_DATA_STREAM_EXTRA1=10, /* Dependent on the autopilot
     * MAV_DATA_STREAM_EXTRA2=11, /* Dependent on the autopilot
     * MAV_DATA_STREAM_EXTRA3=12, /* Dependent on the autopilot
     * MAV_DATA_STREAM_ENUM_END=13,
     *
     * Data in PixHawk available in:
     *  - Battery, amperage and voltage (SYS_STATUS) in MAV_DATA_STREAM_EXTENDED_STATUS
     *  - Gyro info (IMU_SCALED) in MAV_DATA_STREAM_EXTRA1
     */

    // To be setup according to the needed information to be requested from the Pixhawk
    const int  maxStreams = 2;
    const uint8_t MAVStreams[maxStreams] = {MAV_DATA_STREAM_EXTENDED_STATUS, MAV_DATA_STREAM_EXTRA1};
    const uint16_t MAVRates[maxStreams] = {0x02,0x05};

    for (int i=0; i < maxStreams; i++) {
        /*
         * mavlink_msg_request_data_stream_pack(system_id, component_id,
         *    &msg,
         *    target_system, target_component,
         *    MAV_DATA_STREAM_POSITION, 10000000, 1);
         *
         * mavlink_msg_request_data_stream_pack(uint8_t system_id, uint8_t component_id,
         *    mavlink_message_t* msg,
         *    uint8_t target_system, uint8_t target_component, uint8_t req_stream_id,
         *    uint16_t req_message_rate, uint8_t start_stop)
         *
         */
        mavlink_msg_request_data_stream_pack(2, 200, &msg, 1, 0, MAVStreams[i], MAVRates[i], 1);
        uint16_t len = mavlink_msg_to_send_buffer(buf, &msg);
        int ret = sendto(socket_fd, buf, len, 0, (const struct sockaddr*)src_addr, src_addr_len);
        //printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n");
        if (ret != len) {
            //printf(" CUSTOM sendto error: %s\n", strerror(errno));
        } else {
            //printf("CUSTOM Sent\n");
        }
    }
}