//
// Created by fabian on 24.12.23.
//
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include "CircularBuffer.h"

#include "DataDistributor.h"
#include "EnergyCalculator.h"

TEST_CASE( "Energychecker ", "" ) {
    DataDistributor distributor(5);
    distributor.
}