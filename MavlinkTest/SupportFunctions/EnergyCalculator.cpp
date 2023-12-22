//
// Created by fabian on 21.12.23.
//

#include "EnergyCalculator.h"


EnergyCalculator::EnergyCalculator(size_t buffersize, DataDistributor &distributor) :
        Energybuffer(buffersize),
        Energybufferderivation(buffersize),
        dataDistributor(distributor) {

}

float EnergyCalculator::calcEnergyederivation() {
    if (Energybuffer.getBufferSize() == 1){
        // The first derivitif is always x-0 so we just have x
        Energybufferderivation.insert(Energybuffer.getIndex(0));
    }
    // 0 1 2 3 4 5 6 Energy
    // 1 1 1 1 1 1   Derivation
    float derivation = Energybuffer.getLatest()-Energybuffer.getIndex(Energybuffer.getBufferSize()-1);
    Energybufferderivation.insert(derivation);
}