//
// Created by fabian on 11.12.23.
//

#ifndef AUTONOMOUS_SOARING_SENDERCLASS_INTERFACE_H
#define AUTONOMOUS_SOARING_SENDERCLASS_INTERFACE_H

#include "MavlinkHeader.h"
#include "sys/socket.h"
#include <iostream>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <vector>
#include <array>


class SenderClass_Interface {
public:
    virtual ~SenderClass_Interface() {}

    virtual uint8_t send_some(mavlink_message_t message) = 0;

    virtual uint8_t Mav_Request_Data(uint8_t MAVStreams[], uint16_t MAVRates[], int MavStreamSize,
                                     int MavRateSize) = 0; // check in function sizeof(MAVStreams) must equal to sizeof(MAVRates)
    virtual uint8_t Mav_Recive(std::vector<mavlink_message_t> &message, std::vector<mavlink_status_t> &status) = 0;

    virtual uint8_t send_heartbeat() = 0;

};


#endif //AUTONOMOUS_SOARING_SENDERCLASS_INTERFACE_H
