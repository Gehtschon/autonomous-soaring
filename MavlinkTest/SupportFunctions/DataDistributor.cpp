//
// Created by fabian on 24.12.23.
//

#include "DataDistributor.h"
#include "EnergyCalculator.h"

DataDistributor::DataDistributor() : RollBuffer(5), PitchBuffer(5), YawBuffer(5),
                                     AirSpeedBuffer(5), GroundSpeedBuffer(5), AltBuffer(5), ClimbRateBuffer(5),
                                     EnergyBuffer(5), Energybufferderivation(5), LatitudeBuffer(5),
                                     LongitudeBuffer(5), HeadingBuffer(5){
    // Additional initialization if needed
    createEnergyCalculator();


}


DataDistributor::DataDistributor(size_t arraySize) :
        RollBuffer(arraySize),
        PitchBuffer(arraySize),
        YawBuffer(arraySize),
        GroundSpeedBuffer(arraySize),
        AirSpeedBuffer(arraySize),
        AltBuffer(arraySize),
        ClimbRateBuffer(arraySize),
        EnergyBuffer(arraySize),
        Energybufferderivation(arraySize),
        LatitudeBuffer(arraySize),
        LongitudeBuffer(arraySize),
        HeadingBuffer(arraySize) {
    createEnergyCalculator();

}


void DataDistributor::createEnergyCalculator() {
    energyCalculator = new EnergyCalculator(*this);
}

void DataDistributor::decodeMessage(const std::vector<mavlink_message_t> &message,
                                    const std::vector<mavlink_status_t> &status) {
    // Multiple messages can be received at once, so we need to iterate over them
    for (const auto &msg: message) {
        // Handle message based on its type
        // If more messages need to be handled, just add more cases to this switch
        switch (msg.msgid) {

            case MAVLINK_MSG_ID_HEARTBEAT:
                // handle_heartbeat(&msg);
                break;

                // new case for position data longitude and latitude

            case MAVLINK_MSG_ID_GLOBAL_POSITION_INT: {
                mavlink_global_position_int_t global_position_int;
                mavlink_msg_global_position_int_decode(&msg, &global_position_int);
                std::cout << "1" << std::endl;
                LatitudeBuffer.insert(global_position_int.lat);
                LongitudeBuffer.insert(global_position_int.lon);
                HeadingBuffer.insert(global_position_int.hdg);
                break;
            }

            case MAVLINK_MSG_ID_VFR_HUD: {
                std::cout<< "2" << std::endl;
                mavlink_vfr_hud_t VFR;
                mavlink_msg_vfr_hud_decode(&msg, &VFR);
                AirSpeedBuffer.insert(VFR.airspeed);
                GroundSpeedBuffer.insert(VFR.groundspeed);
                AltBuffer.insert(VFR.alt);
                ClimbRateBuffer.insert(VFR.climb);
                calcEnergy();
                break;
            }

            case MAVLINK_MSG_ID_ATTITUDE: {
                mavlink_attitude_t attitude;
                mavlink_msg_attitude_decode(&msg, &attitude);
                RollBuffer.insert(attitude.roll);
                PitchBuffer.insert(attitude.pitch);
                YawBuffer.insert(attitude.yaw);
                break;
            }


        }
    }

}


void DataDistributor::calcEnergy() {
    auto Energyvalue = energyCalculator->getEnergy();
    Energy energy(Energyvalue);
    // set the position data in the energy buffer if it is not empty
    if (LatitudeBuffer.isEmpty()==false && LongitudeBuffer.isEmpty()==false) {
        auto lat = LatitudeBuffer.getLatest();
        auto lon = LongitudeBuffer.getLatest();
        energy.setLat(lat);
        energy.setLon(lon);
    }
    EnergyBuffer.insert(energy);
    auto energyDerValue = energyCalculator->getEnergyDerivation();
    Energy energyDer(energyDerValue);
    Energybufferderivation.insert(energyDer);
}

const CircularBuffer<float> &DataDistributor::getRollBuffer() const {
    return RollBuffer;
}

const CircularBuffer<float> &DataDistributor::getPitchBuffer() const {
    return PitchBuffer;
}

const CircularBuffer<float> &DataDistributor::getYawBuffer() const {
    return YawBuffer;
}

const CircularBuffer<float> &DataDistributor::getGroundSpeedBuffer() const {
    return GroundSpeedBuffer;
}

const CircularBuffer<float> &DataDistributor::getAirSpeedBuffer() const {
    return AirSpeedBuffer;
}

const CircularBuffer<float> &DataDistributor::getAltBuffer() const {
    return AltBuffer;
}

const CircularBuffer<float> &DataDistributor::getClimbRateBuffer() const {
    return ClimbRateBuffer;
}


const CircularBuffer<Energy> &DataDistributor::getEnergyBuffer() const {
    return EnergyBuffer;
}

const CircularBuffer<Energy> &DataDistributor::getEnergybufferderivation() const {
    return Energybufferderivation;
}

void DataDistributor::generateFilledBuffers() {
    size_t vectorLen = RollBuffer.getMaxSize();
    std::vector<float> Values; // dummy values

    for (int i = 0; i < vectorLen; ++i) {
        Values.push_back(static_cast<float>(i)); // Casting to float for consistency
    }

    for (int i = 0; i < vectorLen; ++i) {
        RollBuffer.insert(Values[i]);
        PitchBuffer.insert(Values[i]);
        YawBuffer.insert(Values[i]);
        GroundSpeedBuffer.insert(Values[i]);
        AirSpeedBuffer.insert(Values[i]);
        AltBuffer.insert(Values[i]);
        ClimbRateBuffer.insert(Values[i]);
        auto Energyvalue = energyCalculator->getEnergy();
        Energy energy(Energyvalue);
        energy.setTimeMilliSeconds(i*1000);
        EnergyBuffer.insert(energy);
        auto energyDerValue = energyCalculator->getEnergyDerivation();
        Energy energyDer(energyDerValue);
        Energybufferderivation.insert(energyDer);
    }
}

long DataDistributor::getTimeMillis() {
    auto currentTime = std::chrono::system_clock::now();

    // Convert the time point to milliseconds since the epoch
    auto millisecondsSinceEpoch = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime.time_since_epoch());

    // Extract the current millisecond within the day
    auto millisecondsWithinDay = millisecondsSinceEpoch.count() % 86400000; // 86400000 milliseconds in a day

    return millisecondsWithinDay;
}
