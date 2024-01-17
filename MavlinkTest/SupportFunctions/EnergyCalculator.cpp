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
// 0 1 2 3 4 5 6 Energyvalue
// 1 1 1 1 1 1   Derivation
    auto energybuffer = dataDistributor->getEnergyBuffer();
    if (energybuffer.getBufferSize() < 2) {
        Energy energyob = energybuffer.getLatest();
        return energyob;
    }
    auto e_0 = energybuffer.getLatest();
    auto e_1 = energybuffer.getIndex(energybuffer.getBufferSize() - 2);

    auto energydiff = e_0.getEnergyvalue()-e_1.getEnergyvalue();
    auto timediff_milli = (e_0.getTimeMilliSeconds() - e_1.getTimeMilliSeconds());
    float timediff = static_cast<float>(timediff_milli)/1000.0;

    float energyderivation = energydiff/timediff;

    auto energyob = Energy(energyderivation);

    return energyob;
}

uint64_t EnergyCalculator::calcRadius() {

}