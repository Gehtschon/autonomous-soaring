#define CATCH_CONFIG_MAIN

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include "CircularBuffer.h"

#include <cstdlib>
#include <thread>
#include <iostream>
#include <csignal>

#include "SerialPort.h"
#include "DataDistributor.h"
// Assume you have a SerialPort class implementation

#define BufferSize 10

// Function to execute a shell command and capture its exit code
int executeCommand(const char* command) {
    return system(command);
}

// Placeholder for cleanup function or destructor to stop Linux programs
void stopLinuxPrograms() {
    // Add logic to stop or terminate Linux programs
    // For example, send signals to stop processes or kill them
    system("pkill -f socat");
    system("pkill -f sim_vehicle.py");
}

void sigHandler(int signo) {
    if (signo == SIGCHLD) {
        // Child process terminated, handle as needed
    }
}

TEST_CASE("Integration Tests with External Commands and Serial Communication", "") {
    signal(SIGCHLD, sigHandler);

    // Start socat
    int socatResult = executeCommand("socat -d -d pty,raw,echo=0,b57600 pty,raw,echo=0,b57600 &");
    REQUIRE(socatResult == 0); // Check if socat started successfully

    // Wait for a short time to ensure socat has started
    std::this_thread::sleep_for(std::chrono::seconds(5));

    // Declare SerialPort after socat has been started
    char* uartName = (char*)"/dev/pts/3";
    int baudrate = 57600;
    SerialPort port(uartName, baudrate);

    SECTION("Run software with sim_vehicle.py") {
        // Start sim_vehicle.py in the background
        int simVehicleResult = executeCommand("/home/fabian/Soaring/Ardupilot/ardupilot_soaring/Tools/autotest/sim_vehicle.py -v ArduPlane -f flightaxis:192.168.56.1 --console --map --udp -A --serial5=uart:/dev/pts/3:57600 &");
        REQUIRE(simVehicleResult == 0); // Check if sim_vehicle.py started successfully
        std::this_thread::sleep_for(std::chrono::seconds(30));

        // Add additional checks or assertions as needed
    }

    SECTION("Send command to get data streams") {
        // Use the SerialPort object declared after socat has been started
        // Add more serial communication checks or assertions as needed
        const int maxStreams = 2;
        uint8_t MAVStreams[maxStreams] = {MAV_DATA_STREAM_EXTENDED_STATUS, MAV_DATA_STREAM_EXTRA1};
        uint16_t MAVRates[maxStreams] = {0x02, 0x05};

        REQUIRE(port.Mav_Request_Data(MAVStreams, MAVRates, maxStreams, maxStreams) == 0); // Example assertion
    }

    SECTION("Get Flightsimulation data") {
        // Use the SerialPort object declared after socat has been started
        // Add more assertions related to flightsimulation data
        DataDistributor dataDistributor(BufferSize);
        std::vector<mavlink_message_t> message;
        std::vector<mavlink_status_t> status;
        port.Mav_Recive(message, status);
        //std::cout << "message length: " << message.size() << std::endl;
        dataDistributor.decodeMessage(message, status);
        auto testbuffer = dataDistributor.getAirSpeedBuffer();
        testbuffer.displayBuffer();
        REQUIRE(testbuffer.getIndex(0) != 0);
    }

        // Add more sections for other integration tests if necessary

        // Cleanup after all tests have run
    SECTION("cleanup") {
        stopLinuxPrograms();
    }
}
