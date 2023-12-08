//
// Created by fabian on 30.11.23.
//

#include "DataDistributor.h"

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
                //printf("Airspeed is: %f \n", VFR.airspeed);
                //printf("Groundspeed is: %f \n", VFR.groundspeed);
                //printf("Alt is: %f \n", VFR.alt);
                break;
            }

            case MAVLINK_MSG_ID_ATTITUDE: {
                mavlink_attitude_t attitude;
                mavlink_msg_attitude_decode(&msg, &attitude);
                printf("Roll is: %f \n", (attitude.roll * (180.0 / 3.141592653589793238463)));
                break;
            }


        }
    }
}

void DataDistributor::CreateBufferObjects(size_t Buffersize) {
    AltBuffer = CircularBuffer<float>(5);
    RollBuffer = CircularBuffer<float>(Buffersize);
    PitchBuffer = CircularBuffer<float>(Buffersize);
    YawBuffer = CircularBuffer<float>(Buffersize);
}