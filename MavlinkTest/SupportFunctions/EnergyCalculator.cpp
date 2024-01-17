//
// Created by fabian on 24.12.23.
//

#include "EnergyCalculator.h"

EnergyCalculator::EnergyCalculator(DataDistributor &distributor) :

        dataDistributor(&distributor) {

}

Energy EnergyCalculator::getEnergy() {
    // 1/2g * v² +h
    auto v_airspeed = dataDistributor->getAirSpeedBuffer();
    auto height = dataDistributor->getAltBuffer();
    float e = static_cast<float>((v_airspeed.getLatest() * v_airspeed.getLatest()) / (2.0 * GRAVITATION)) + height.getLatest();
    return Energy(e);

}

Energy EnergyCalculator::getEnergyDerivation() {
    // The buffers for energyvalue and the derivation can look like this:
    // 0 1 2 3 4 5 6 Energyvalue
    // 1 1 1 1 1 1   Derivation
    auto energybuffer = dataDistributor->getEnergyBuffer();
    // If the buffer is smaller than 2, the derivation cannot be calculated, so it returns the latest energyvalue
    if (energybuffer.getBufferSize() < 2) {
        Energy energyob = energybuffer.getLatest();
        return energyob;
    }
    // The derivation is calculated by the difference of the latest and the second latest energyvalue
    auto e_0 = energybuffer.getLatest();
    auto e_1 = energybuffer.getIndex(energybuffer.getBufferSize() - 2);

    auto energydiff = e_0.getEnergyvalue()-e_1.getEnergyvalue();
    auto timediff_milli = (e_0.getTimeMilliSeconds() - e_1.getTimeMilliSeconds());
    float timediff = static_cast<float>(timediff_milli)/1000.0;

    //
    float energyderivation = energydiff/timediff;

    // Create an energy object with the derivation
    auto energyob = Energy(energyderivation);

    return energyob;
}

uint64_t EnergyCalculator::calcRadius() {

}