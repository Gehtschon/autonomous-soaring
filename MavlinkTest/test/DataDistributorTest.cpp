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
        //  0    1.0510    2.2039    3.4587    4.8155    6.2742    7.8349    9.4975   11.2620   13.1284
        std::vector<float> EnergyMatlab = {
                0.0f, 1.0510f, 2.2039f, 3.4587f, 4.8155f, 6.2742f, 7.8349f, 9.4975f, 11.2620f, 13.1284f};

        auto EnergyBuffer = dataDistributor.getEnergyBuffer();
        for (int i = 0; i < BufferSize; ++i) {
            auto Energyobj = EnergyBuffer.getIndex(i);
            // std::cout<< Energyobj.getEnergyvalue() << std::endl;
            REQUIRE_THAT(Energyobj.getEnergyvalue(), Catch::Matchers::WithinRel(EnergyMatlab[i], 0.0001f));
        }
    }

    SECTION("Energy derivation calculation Test") {
        // Energycalculations from Matlab
        //0    1.0510    1.1529    1.2548    1.3568    1.4587    1.5607    1.6626    1.7645    1.8665
        std::vector<float> EnergyderMatlab = {0.0f, 1.0510f, 1.1529f, 1.2548f, 1.3568f, 1.4587f, 1.5607f, 1.6626f,
                                              1.7645f, 1.8665f,};


        auto EnergyderBuffer = dataDistributor.getEnergybufferderivation();
        for (int i = 0; i < BufferSize; ++i) {
            auto Energyobj = EnergyderBuffer.getIndex(i);
            std::cout << Energyobj.getEnergyvalue() << std::endl;
            REQUIRE_THAT(Energyobj.getEnergyvalue(), Catch::Matchers::WithinRel(EnergyderMatlab[i], 0.0001f));
        }


    }

}