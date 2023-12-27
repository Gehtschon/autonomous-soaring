//
// Created by fabian on 27.12.23.
//
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include "CircularBuffer.h"


#include "DataDistributor.h"
#include "Energy.h"

#define BufferSize 10

TEST_CASE("Distribution test, also energy calculation tests.", "") {
    DataDistributor dataDistributor(BufferSize);
    dataDistributor.generateFilledBuffers();


    // creation of the support Vector
    std::vector<float> supportVector; // dummy values
    for (int i = 0; i < BufferSize; ++i) {
        supportVector.push_back(static_cast<float>(i)); // Casting to float for consistency
    }

    // Initial Testing
    REQUIRE(supportVector[0] == 0.0);
    REQUIRE(supportVector[BufferSize - 1] == static_cast<float>(BufferSize - 1));


    SECTION("Testing 1 Buffer (Airspeed)") {
        auto AirSpeedBuffer = dataDistributor.getAirSpeedBuffer();
        for (int i = 0; i < BufferSize; ++i) {
            REQUIRE(AirSpeedBuffer.getIndex(i) == supportVector[i]);
        }
    }

    SECTION("Energy calculation Test") {
        // Energycalculations from Matlab
        // 0    5.9050   21.6200   47.1450   82.4800  127.6250  182.5800  247.3450  321.9200  406.3050
        std::vector<float> EnergyMatlab = {0.0f, 5.9050f, 21.6200f, 47.1450f, 82.4800f, 127.6250f, 182.5800f, 247.3450f,
                                           321.9200f, 406.3050f};

        auto EnergyBuffer = dataDistributor.getEnergyBuffer();
        for (int i = 0; i < BufferSize; ++i) {
            auto Energyobj = EnergyBuffer.getIndex(i);
            // std::cout<< Energyobj.getEnergyvalue() << std::endl;
            REQUIRE_THAT(Energyobj.getEnergyvalue(), Catch::Matchers::WithinRel(EnergyMatlab[i], 0.0001f));
        }
    }

    SECTION("Energy derivation calculation Test") {
        // Energycalculations from Matlab
        //0    5.9050   15.7150   25.5250   35.3350   45.1450   54.9550   64.7650   74.5750   84.3850
        std::vector<float> EnergyderMatlab = {0.0f, 5.9050f, 15.7150f, 25.5250f, 35.3350f, 45.1450f, 54.9550f, 64.7650f,
                                          74.5750f, 84.3850f};


        auto EnergyderBuffer = dataDistributor.getEnergybufferderivation();
        for (int i = 0; i < BufferSize; ++i) {
            auto Energyobj = EnergyderBuffer.getIndex(i);
             std::cout<< Energyobj.getEnergyvalue() << std::endl;
            REQUIRE_THAT(Energyobj.getEnergyvalue(), Catch::Matchers::WithinRel(EnergyderMatlab[i], 0.0001f));
        }



    }

}