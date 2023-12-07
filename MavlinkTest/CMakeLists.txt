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
        SupportFunctions/SenderClass.cpp
        SupportFunctions/SenderClass.h
        SupportFunctions/DataDistributor.cpp
        SupportFunctions/DataDistributor.h
        SupportFunctions/CircularBuffer.cpp
        SupportFunctions/CircularBuffer.h
)

include_directories(
        SupportFunctions
        c_library_v2-master
        c_library_v2-master/ardupilotmega

)
add_subdirectory(./lib/Catch2)

# test sources
file(GLOB_RECURSE test_SRCS
        "${PROJECT_SOURCE_DIR}/test/*.cpp"
        "${PROJECT_SOURCE_DIR}/SupportFunctions/*.cpp"
)
add_executable(buffertest.elf ${test_SRCS}
    SupportFunctions/CircularBuffer.cpp)
target_link_libraries(buffertest.elf Catch2::Catch2WithMain)
target_include_directories(buffertest.elf PRIVATE SupportFunctions)

