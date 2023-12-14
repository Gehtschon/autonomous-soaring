//
// Created by fabian on 14.12.23.
//

#include "catch2/catch_test_macros.hpp"
#include "catch2/matchers/catch_matchers_floating_point.hpp"

#include "SerialPort.h"
#include "SenderClass_Interface.h"

TEST_CASE( "Check Serial ", "" ){
    char *uart_name = (char*)"/dev/ttyS11";
    int baudrate = 57600;
    SerialPort port(uart_name, baudrate);
    REQUIRE(1 == 1);

}