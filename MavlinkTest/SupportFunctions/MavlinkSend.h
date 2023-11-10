//
// Created by fabian on 10.11.23.
//

#ifndef AUTONOMOUS_SOARING_MAVLINKSEND_H
#define AUTONOMOUS_SOARING_MAVLINKSEND_H


#include "MavlinkHeader.h"
#include "sys/socket.h"


void send_some(int socket_fd, const struct sockaddr_in* src_addr, socklen_t src_addr_len);

#endif //AUTONOMOUS_SOARING_MAVLINKSEND_H
