//
// Created by fabian on 30.11.23.
//

#ifndef AUTONOMOUS_SOARING_DATADISTRIBUTOR_H
#define AUTONOMOUS_SOARING_DATADISTRIBUTOR_H

#include "MavlinkHeader.h"
#include "mavlink_msg_vfr_hud.h"
#include <vector>
#include <CircularBuffer.h>
#include "CircularBuffer.cpp"

class DataDistributor {
private:
    CircularBuffer<float> AltBuffer;
    CircularBuffer<float> RollBuffer;
    CircularBuffer<float> PitchBuffer;
    CircularBuffer<float> YawBuffer;
    void CreateBufferObjects(size_t Buffersize);

public:
    void decodeMessage(const std::vector<mavlink_message_t>& message, const std::vector<mavlink_status_t>& status);

};


#endif //AUTONOMOUS_SOARING_DATADISTRIBUTOR_H
