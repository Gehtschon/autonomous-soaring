//
// Created by fabian on 12.11.23.
//

#include "SenderClass.h"

SenderClass::SenderClass(int socketFd) {
     src_addr_len = sizeof(src_addr);
    this->socket_fd  = socketFd;
     // here start to request data
    //void Mav_Request_Data(uint8_t MAVStreams[],int16_t MAVRates[]);
};




uint8_t SenderClass::Mav_Request_Data(uint8_t MAVStreams[],int16_t MAVRates[],int MavStreamSize, int MavRateSize){

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


uint8_t SenderClass::send_some(mavlink_message_t message){
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