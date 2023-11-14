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


    /**
 * Activating datastreams on flightcontroller
 *
 * Activating datastreams on flighcontroller. The 2 Arrays need tro be same size!
 * use this function to activate datastreams that should be periodicly updatet
 *
 * @param MAVStreams Wich Streams are activated more infos in common.h: enum MAV_DATA_STREAM
 * @param MAVRates Datarates of the Streams
 * @param MavStreamSize Size of the MAVStreams Array
 * @param MavStreamSize Size of the MAVRates Array
 * @return
 *   - 99: Different array size
 *   -  1: Failed to send
 *   -  0: No error
 */
    uint8_t Mav_Request_Data(uint8_t MAVStreams[],int16_t MAVRates[],int MavStreamSize, int MavRateSize); // check in function sizeof(MAVStreams) must equal to sizeof(MAVRates)
    // this function is implemented in main, rewrite it here
};


#endif //AUTONOMOUS_SOARING_SENDERCLASS_H
