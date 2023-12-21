//
// Created by fabian on 21.12.23.
//

#ifndef AUTONOMOUS_SOARING_ENERGIECALCULATOR_H
#define AUTONOMOUS_SOARING_ENERGIECALCULATOR_H

#include <CircularBuffer.h>

class EnergieCalculator {

private:
    CircularBuffer<float> Energiebuffer;
    CircularBuffer<float> Energiebufferableitung;
    bool Rising = false;
    float calcEnergie(const CircularBuffer<float> Airspeed, const CircularBuffer<float> Height);
    float calcEnergiederivation();

public:
    EnergieCalculator();


};


#endif //AUTONOMOUS_SOARING_ENERGIECALCULATOR_H
