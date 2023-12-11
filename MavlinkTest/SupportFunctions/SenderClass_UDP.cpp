//
// Created by fabian on 12.11.23.
//

#include "SenderClass_UDP.h"

SenderClass_UDP::~SenderClass_UDP() noexcept {
// ToDO Close socket and delete pointers
};


SenderClass_UDP::SenderClass_UDP(int socketFd) {

    src_addr_len = sizeof(src_addr);
    this->socket_fd  = socketFd;
    // Bind to port
    struct sockaddr_in addr = {};
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    inet_pton(AF_INET, "0.0.0.0", &(addr.sin_addr)); // listen on all network interfaces
    addr.sin_port = htons(14550); // default port on the ground

    if (bind(socket_fd, (struct sockaddr*)(&addr), sizeof(addr)) != 0) {
        printf("bind error: %s\n", strerror(errno));
        // here the object must de destroyed
    }

    // We set a timeout at 100ms to prevent being stuck in recvfrom for too
    // long and missing our chance to send some stuff.
    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 100000;
    if (setsockopt(socket_fd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
        printf("setsockopt error: %s\n", strerror(errno));
        // here the object must de destroyed
    }

    struct sockaddr_in src_addr = {};
    socklen_t src_addr_len = sizeof(src_addr);

};




uint8_t SenderClass_UDP::Mav_Request_Data(uint8_t MAVStreams[], uint16_t MAVRates[], int MavStreamSize, int MavRateSize){

    uint8_t retVal = 99;
    bool fail = false;
    mavlink_message_t msg;
    uint8_t buf[MAVLINK_MAX_PACKET_LEN];

    if(MavStreamSize != MavRateSize){
        return 99;
    }

    for (int i = 0; i < MavStreamSize; ++i) {
        mavlink_msg_request_data_stream_pack(2, 200, &msg, 1, 0, MAVStreams[i], MAVRates[i], 1);
        int16_t len = mavlink_msg_to_send_buffer(buf, &msg);
        int ret = sendto(socket_fd, buf, len, 0, (const struct sockaddr*)&this->src_addr, src_addr_len);

        if (ret != len){
            fail = true;
        }

    }

    if (fail == true){
        return 1;
    } else{
        return 0;
    }


}


uint8_t SenderClass_UDP::send_some(mavlink_message_t message){
    uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
    int len = mavlink_msg_to_send_buffer(buffer, &message);
    bool fail = false;
    int ret = sendto(socket_fd, buffer, len, 0, (const struct sockaddr*)&this->src_addr, src_addr_len);

    if (ret != len){
        fail = true;
    }

    if (fail == true){
        return 1;
    } else{
        return 0;
    }
}


uint8_t SenderClass_UDP::send_heartbeat()
{

    mavlink_message_t message;
    bool fail = false;
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

    int ret = sendto(socket_fd, buffer, len, 0, (const struct sockaddr*)&this->src_addr, src_addr_len);
    if (ret != len){
        fail = true;
    }

    if (fail == true){
        return 1;
    } else{
        return 0;
    }
}

uint8_t SenderClass_UDP::Mav_Recive(std::vector<mavlink_message_t> &message, std::vector<mavlink_status_t> &status){

    mavlink_message_t message_internaly;
    mavlink_status_t status_internaly;
    char buffer[2048]; // enough for MTU 1500 bytes
    bool messageFound = false;


    const int ret = recvfrom(socket_fd, buffer, sizeof(buffer), 0, (struct sockaddr*)&this->src_addr, &src_addr_len);

    if (ret < 0) {
        // printf("recvfrom error: %s\n", strerror(errno));
    } else if (ret == 0) {
        // peer has done an orderly shutdown
        return 1; // Failed to recive message
    }

    for (int i = 0; i < ret; ++i) {
        if (mavlink_parse_char(MAVLINK_COMM_0, buffer[i], &message_internaly, &status_internaly) == 1){
            messageFound = true;
            message.push_back(message_internaly);
            status.push_back(status_internaly);
        }

    }

    if (messageFound == false){
        return 2;
    }

    return 0;

}