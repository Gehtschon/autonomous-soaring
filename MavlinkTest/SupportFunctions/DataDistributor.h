//
// Created by fabian on 30.11.23.
//

#ifndef AUTONOMOUS_SOARING_DATADISTRIBUTOR_H
#define AUTONOMOUS_SOARING_DATADISTRIBUTOR_H

#include "MavlinkHeader.h"
#include "mavlink_msg_vfr_hud.h"
#include <vector>
#include <CircularBuffer.h>

class DataDistributor {
private:
    CircularBuffer<float> RollBuffer;
    CircularBuffer<float> PitchBuffer;
    CircularBuffer<float> YawBuffer;
    CircularBuffer<float> GroundSpeedBuffer;
    CircularBuffer<float> AirSpeedBuffer;
    CircularBuffer<float> AltBuffer;
    CircularBuffer<float> ClimbRateBuffer;


public:
    DataDistributor();
    DataDistributor(size_t arraySize);
    void decodeMessage(const std::vector<mavlink_message_t> &message, const std::vector<mavlink_status_t> &status);

    const CircularBuffer<float> &getRollBuffer() const;

    const CircularBuffer<float> &getPitchBuffer() const;

    const CircularBuffer<float> &getYawBuffer() const;

    const CircularBuffer<float> &getGroundSpeedBuffer() const;

    const CircularBuffer<float> &getAirSpeedBuffer() const;

    const CircularBuffer<float> &getAltBuffer() const;

    const CircularBuffer<float> &getClimbRateBuffer() const;

};


#endif //AUTONOMOUS_SOARING_DATADISTRIBUTOR_H
