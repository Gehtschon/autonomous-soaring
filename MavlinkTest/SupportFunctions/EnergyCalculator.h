//
// Created by fabian on 24.12.23.
//

#ifndef AUTONOMOUS_SOARING_ENERGYCALCULATOR_H
#define AUTONOMOUS_SOARING_ENERGYCALCULATOR_H

#include "CircularBuffer.h"
#include "DataDistributor.h"
#include "Energy.h"

#define GRAVITATION 9.81

class DataDistributor;  // Forward declaration

class EnergyCalculator {

private:
    DataDistributor* dataDistributor;
    Energy calcEnergyederivation();
    uint64_t avergeRadius = 30; // in meters

public:
    EnergyCalculator(DataDistributor &distributor);

    Energy getEnergy();
    Energy getEnergyDerivation();

    // function to determine the radius of a thermal
    uint64_t calcRadius();




};



#endif //AUTONOMOUS_SOARING_ENERGYCALCULATOR_H
