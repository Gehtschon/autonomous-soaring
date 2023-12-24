//
// Created by fabian on 24.12.23.
//
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include "CircularBuffer.h"

#include "DataDistributor.h"


#define BufferSize 10

TEST_CASE( "Energychecker ", "" ) {
    DataDistributor dataDistributor(BufferSize);
    REQUIRE(1==1);
}