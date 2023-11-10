//
// Created by fabian on 10.11.23.
//

#ifndef AUTONOMOUS_SOARING_MAVLINKHEARTBEAT_H
#define AUTONOMOUS_SOARING_MAVLINKHEARTBEAT_H

#include <MavlinkHeader.h>
#include <sys/socket.h>


void handle_heartbeat(const mavlink_message_t* message);
void send_heartbeat(int socket_fd, const struct sockaddr_in* src_addr, socklen_t src_addr_len);

#endif //AUTONOMOUS_SOARING_MAVLINKHEARTBEAT_H
