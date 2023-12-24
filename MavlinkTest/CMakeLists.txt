cmake_minimum_required(VERSION 3.23)
project(autonomous_soaring)

set(CMAKE_CXX_STANDARD 20)

add_executable(autonomous_soaring
        main.cpp
        SupportFunctions/MavlinkHeartbeat.cpp
        SupportFunctions/MavlinkHeader.h
        SupportFunctions/MavlinkHeartbeat.h
        SupportFunctions/MavlinkSend.h
        SupportFunctions/MavlinkSend.cpp
        SupportFunctions/SenderClass_UDP.cpp
        SupportFunctions/SenderClass_UDP.h
        SupportFunctions/CircularBuffer.h
        SupportFunctions/SenderClass_Interface.h
        SupportFunctions/SerialPort.cpp
        SupportFunctions/SerialPort.h
        SupportFunctions/DataDistributor.cpp
        SupportFunctions/DataDistributor.h
        SupportFunctions/EnergyCalculator.cpp
        SupportFunctions/EnergyCalculator.h

)

include_directories(
        SupportFunctions
        c_library_v2-master
        c_library_v2-master/ardupilotmega
        c_library_v2-master/common

)
add_subdirectory(./lib/Catch2)

# test sources buffertest
file(GLOB_RECURSE test_SRCS
        "${PROJECT_SOURCE_DIR}/test/buffertest.cpp"
        "${PROJECT_SOURCE_DIR}/SupportFunctions/*.cpp"
)
add_executable(buffertest.elf ${test_SRCS}
    SupportFunctions/CircularBuffer.h
        test/buffertest.cpp
        test/Energytester.cpp)
target_link_libraries(buffertest.elf Catch2::Catch2WithMain)
target_include_directories(buffertest.elf PRIVATE SupportFunctions)

# test sources Serialport
file(GLOB_RECURSE test_SRCS_UART
        "${PROJECT_SOURCE_DIR}/test/Serialporttester.cpp"
        "${PROJECT_SOURCE_DIR}/SupportFunctions/*.cpp"
)
add_executable(SerialportTester.elf ${test_SRCS_UART}
        SupportFunctions/SerialPort.h
        test/Serialporttester.cpp)
target_link_libraries(SerialportTester.elf Catch2::Catch2WithMain)
target_include_directories(SerialportTester.elf PRIVATE SupportFunctions)


# test sources Energytester
file(GLOB_RECURSE test_SRCS_Energy
        "${PROJECT_SOURCE_DIR}/test/Energytester.cpp"
        "${PROJECT_SOURCE_DIR}/SupportFunctions/*.cpp"
)
add_executable(Energytester.elf ${test_SRCS_Energy}
        SupportFunctions/SerialPort.h
        test/Energytester.cpp)
target_link_libraries(Energytester.elf Catch2::Catch2WithMain)
target_include_directories(Energytester.elf PRIVATE SupportFunctions)
