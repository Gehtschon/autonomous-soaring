//
// Created by fabian on 21.12.23.
//

#include "EnergyCalculator.h"


EnergyCalculator::EnergyCalculator(size_t buffersize, DataDistributor &distributor) :
        Energybuffer(buffersize),
        Energybufferderivation(buffersize),
        dataDistributor(&distributor) {

}

float EnergyCalculator::calcEnergyederivation() {
    if (Energybuffer.getBufferSize() == 1){
        // The first derivitif is always x-0 so we just have x
        auto energyDerivation = dataDistributor->getEnergyBuffer();

        dataDistributor->addEnergyDerivation(energyDerivation.getIndex(0));

    }
    // 0 1 2 3 4 5 6 Energy
    // 1 1 1 1 1 1   Derivation

    auto Energy = dataDistributor->getEnergyBuffer();

    auto Energy_0 = Energy.getLatest();
    auto Energy_1 = Energy.getIndex(Energy.getBufferSize()-1);

    auto derivation = Energy_0 - Energy_1;

    dataDistributor->addEnergyDerivation(derivation);

    return derivation;


}