//
// Created by fabian on 24.12.23.
//

#ifndef AUTONOMOUS_SOARING_DATADISTRIBUTOR_H
#define AUTONOMOUS_SOARING_DATADISTRIBUTOR_H


#include "MavlinkHeader.h"
#include "mavlink_msg_vfr_hud.h"
#include <vector>
#include <CircularBuffer.h>
#include "Energy.h"

class EnergyCalculator;  // Forward declaration

class DataDistributor {
private:
    CircularBuffer<float> RollBuffer;
    CircularBuffer<float> PitchBuffer;
    CircularBuffer<float> YawBuffer;
    CircularBuffer<float> GroundSpeedBuffer;
    CircularBuffer<float> AirSpeedBuffer;
    CircularBuffer<float> AltBuffer;
    CircularBuffer<float> ClimbRateBuffer;
    CircularBuffer<Energy> EnergyBuffer;
    CircularBuffer<Energy> Energybufferderivation;
    EnergyCalculator *energyCalculator;
    // add the buffers you created for the new data
    CircularBuffer<int32_t> LatitudeBuffer;
    CircularBuffer<int32_t> LongitudeBuffer;
    //CircularBuffer<int32_t> AltitudeBuffer;
    //CircularBuffer<int32_t> RelativeAltitudeBuffer;
    CircularBuffer<int16_t> HeadingBuffer;


    void createEnergyCalculator();


public:
    DataDistributor();

    DataDistributor(size_t arraySize);

/**
 * @brief Decodes the mavlink message and stores the data in the corresponding buffer
 * @param message the mavlink message to decode
 * @param status used for chekcing if the message is complete and not corrupted
 */
    void decodeMessage(const std::vector<mavlink_message_t> &message, const std::vector<mavlink_status_t> &status);


/**
 * @brief Calculates the energy from the data in the buffers and stores it in the energy buffer
 * it also set the longitude and latitude in the energy buffer
 */
    void calcEnergy();


    const CircularBuffer<float> &getRollBuffer() const;

    const CircularBuffer<float> &getPitchBuffer() const;

    const CircularBuffer<float> &getYawBuffer() const;

    const CircularBuffer<float> &getGroundSpeedBuffer() const;

    const CircularBuffer<float> &getAirSpeedBuffer() const;

    const CircularBuffer<float> &getAltBuffer() const;

    const CircularBuffer<float> &getClimbRateBuffer() const;

    void addEnergy(const float Energy);

    void addEnergyDerivation(const float Energyder);

    const CircularBuffer<Energy> &getEnergyBuffer() const;

    const CircularBuffer<Energy> &getEnergybufferderivation() const;

/**
 * @brief Returns the current time in milliseconds
 * @return
 */
    long getTimeMillis();

    // for testing only
    void generateFilledBuffers();


};


#endif //AUTONOMOUS_SOARING_DATADISTRIBUTOR_H
