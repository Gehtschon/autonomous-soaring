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
#include <iostream>

//#include "c_library_v2-master/common/mavlink.h"
#include <MavlinkHeartbeat.h>
#include "SenderClass.h"
#include "CircularBuffer.h"
#include "CircularBuffer.cpp"


int main(int argc, char* argv[])
{

    std::cout << "Startup\n";
    // Open UDP socket
    const int socket_fd = socket(PF_INET, SOCK_DGRAM, 0);


    if (socket_fd < 0) {
        printf("socket error: %s\n", strerror(errno));
        return -1;
    }

    SenderClass senderObject(socket_fd);

    const int  maxStreams = 2;
    uint8_t MAVStreams[maxStreams] = {MAV_DATA_STREAM_EXTENDED_STATUS, MAV_DATA_STREAM_EXTRA1};
    uint16_t MAVRates[maxStreams] = {0x02,0x05};
    senderObject.Mav_Request_Data(MAVStreams,MAVRates,maxStreams,maxStreams);




    std::cout << "Startup done\n";
    while (true) {
        // For illustration purposes we don't bother with threads or async here
        // and just interleave receiving and sending.
        // This only works  if receive_some returns every now and then.

        //Todo print the messages recive shlould be impklemented butr check it again!!

        std::vector<mavlink_message_t> message;
        std::vector<mavlink_status_t> status;

        senderObject.Mav_Recive(message,status);
        //std::cout << "message length: " << message.size() << std::endl;

        for (const auto& msg : message) {
            switch (msg.msgid) {
                case MAVLINK_MSG_ID_HEARTBEAT:
                    handle_heartbeat(&msg);
                    break;

                case MAVLINK_MSG_ID_VFR_HUD: {
                    mavlink_vfr_hud_t VFR;
                    mavlink_msg_vfr_hud_decode(&msg, &VFR);
                    printf("Airspeed is: %f \n", VFR.airspeed);
                    printf("Groundspeed is: %f \n", VFR.groundspeed);
                    printf("Alt is: %f \n", VFR.alt);
                    break;
                }

                case MAVLINK_MSG_ID_ATTITUDE: {  // #30

                    /* Message decoding: PRIMITIVE
                     *    mavlink_msg_attitude_decode(const mavlink_message_t* msg, mavlink_attitude_t* attitude)
                     */
                    mavlink_attitude_t attitude;
                    mavlink_msg_attitude_decode(&msg, &attitude);
                    printf("Roll is: %f \n", (attitude.roll*(180.0/3.141592653589793238463)));
                    break;
                }
            }
        }





       // receive_some(socket_fd, &src_addr, &src_addr_len, &src_addr_set);



//        if (src_addr_set) {
 //           send_some(socket_fd, &src_addr, src_addr_len);
   //     }
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
       // testSend(socket_fd, src_addr, src_addr_len);
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

