//
// Created by fabian on 14.12.23.
//

#ifndef AUTONOMOUS_SOARING_SERIALPORT_H
#define AUTONOMOUS_SOARING_SERIALPORT_H

#include "SenderClass_Interface.h"
#include "MavlinkHeader.h"
#include <cstdlib>
#include <stdio.h>   // Standard input/output definitions
#include <unistd.h>  // UNIX standard function definitions
#include <fcntl.h>   // File control definitions
#include <termios.h> // POSIX terminal control definitions
#include <pthread.h> // This uses POSIX Threads
#include <signal.h>



#include <common/mavlink.h>

class SerialPort {
private:
    const char *uart_name;
    int baudrate;
    int fd;

    int open_port(const char *port);

    bool setup_port(int baud, int data_bits, int stop_bits, bool parity, bool hardware_control);

    int read_port(uint8_t &cp);

public:
    SerialPort();
    SerialPort(const char *uartName, int baudrate_);

    uint8_t send_some(mavlink_message_t message);

    uint8_t Mav_Request_Data(uint8_t MAVStreams[], uint16_t MAVRates[], int MavStreamSize,
                             int MavRateSize);

    uint8_t Mav_Recive(std::vector<mavlink_message_t> &message, std::vector<mavlink_status_t> &status);

    uint8_t send_heartbeat();
};


#endif //AUTONOMOUS_SOARING_SERIALPORT_H
