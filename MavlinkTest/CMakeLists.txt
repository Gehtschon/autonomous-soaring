cmake_minimum_required(VERSION 3.23)
project(autonomous_soaring)

set(CMAKE_CXX_STANDARD 20)

add_executable(autonomous_soaring main.cpp
        SupportFunctions/MavlinkHeartbeat.cpp
        SupportFunctions/MavlinkHeader.h
        SupportFunctions/MavlinkHeartbeat.h
        SupportFunctions/MavlinkSend.h
        SupportFunctions/MavlinkSend.cpp
        SupportFunctions/SenderClass.cpp
        SupportFunctions/SenderClass.h)

include_directories(
        SupportFunctions
        c_library_v2-master
        c_library_v2-master/ardupilotmega
)
