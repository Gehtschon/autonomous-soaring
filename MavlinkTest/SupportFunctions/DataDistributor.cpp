//
// Created by fabian on 30.11.23.
//

#include "DataDistributor.h"

DataDistributor::DataDistributor() : RollBuffer(5), PitchBuffer(5), YawBuffer(5),
                                     AirSpeedBuffer(5), GroundSpeedBuffer(5), AltBuffer(5), ClimbRateBuffer(5) {

}

DataDistributor::DataDistributor(size_t arraySize) :
        RollBuffer(arraySize),
        PitchBuffer(arraySize),
        YawBuffer(arraySize),
        GroundSpeedBuffer(arraySize),
        AirSpeedBuffer(arraySize),
        AltBuffer(arraySize),
        ClimbRateBuffer(arraySize) {

}


void DataDistributor::decodeMessage(const std::vector<mavlink_message_t> &message,
                                    const std::vector<mavlink_status_t> &status) {
    for (const auto &msg: message) {
        switch (msg.msgid) {

            case MAVLINK_MSG_ID_HEARTBEAT:
                // handle_heartbeat(&msg);
                break;

            case MAVLINK_MSG_ID_VFR_HUD: {
                mavlink_vfr_hud_t VFR;
                mavlink_msg_vfr_hud_decode(&msg, &VFR);
                printf("Airspeed is: %f \n", VFR.airspeed);
                printf("Groundspeed is: %f \n", VFR.groundspeed);
                //printf("Alt is: %f \n", VFR.alt);
                AirSpeedBuffer.insert(VFR.airspeed);
                GroundSpeedBuffer.insert(VFR.groundspeed);
                AltBuffer.insert(VFR.alt);
                ClimbRateBuffer.insert(VFR.climb);

                break;
            }

            case MAVLINK_MSG_ID_ATTITUDE: {
                mavlink_attitude_t attitude;
                mavlink_msg_attitude_decode(&msg, &attitude);
                //printf("Roll is: %f \n", (attitude.roll * (180.0 / 3.141592653589793238463)));
                RollBuffer.insert(attitude.roll);
                PitchBuffer.insert(attitude.pitch);
                YawBuffer.insert(attitude.yaw);
                break;
            }


        }
    }

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

