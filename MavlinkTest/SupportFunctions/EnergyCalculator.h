//
// Created by fabian on 21.12.23.
//

#ifndef AUTONOMOUS_SOARING_ENERGYCALCULATOR_H
#define AUTONOMOUS_SOARING_ENERGYCALCULATOR_H

#include <CircularBuffer.h>
#include "DataDistributor.h"

class EnergyCalculator {

private:
    CircularBuffer<float> Energybuffer;
    CircularBuffer<float> Energybufferderivation;
    bool Rising = false;
    DataDistributor* dataDistributor;
    float calcEnergyederivation();

public:
    EnergyCalculator(size_t buffersize, DataDistributor &distributor);
    float getEnergy();
    float getEnergyderivation();
    bool  currentlyRising();

};


#endif //AUTONOMOUS_SOARING_ENERGYCALCULATOR_H
