//
// Created by fabian on 12.11.23.
//

#include "SenderClass.h"

SenderClass::SenderClass(int socketFd) : socket_fd(socketFd) {
    src_addr_len = sizeof(src_addr);

    Mav_Request_Data(socket_fd, &src_addr, src_addr_len);
};

