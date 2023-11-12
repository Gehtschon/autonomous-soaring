//
// Created by fabian on 12.11.23.
//

#ifndef AUTONOMOUS_SOARING_SENDERCLASS_H
#define AUTONOMOUS_SOARING_SENDERCLASS_H

#include "MavlinkHeader.h"
#include "sys/socket.h"
#include <iostream>
#include <arpa/inet.h>
#include <netinet/in.h>

class SenderClass {
private:
    int socket_fd;
    struct sockaddr_in src_addr = {};
    socklen_t src_addr_len;
public:
    explicit SenderClass(int socketFd);
    void send_some(socklen_t src_addr_len,mavlink_message_t message);
    void Mav_Request_Data(uint8_t MAVStreams[],int16_t MAVRates[]); // check in function sizeof(MAVStreams) must equal to sizeof(MAVRates)
    // this function is implemented in main, rewrite it here
};


#endif //AUTONOMOUS_SOARING_SENDERCLASS_H
