//
// Created by fabian on 07.12.23.
//
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include "CircularBuffer.h"




TEST_CASE( "Check Int Buffer ", "" ) {
    CircularBuffer<int> intBuffer(5);
    REQUIRE(intBuffer.getMaxSize() == 5);
    REQUIRE(intBuffer.isEmpty()==true);
    // Insert data into the buffer
    intBuffer.insert(1);

    REQUIRE(intBuffer.getBufferSize() == 1);

    intBuffer.insert(2);

    REQUIRE(intBuffer.getLatest()==2);
    REQUIRE(intBuffer.getBufferSize() == 2);
    REQUIRE(intBuffer.isEmpty()==false);

    intBuffer.insert(3);
    intBuffer.insert(5);
    std::cout<<intBuffer.calculateAverage()<<std::endl;
    REQUIRE_THAT(intBuffer.calculateAverage(), Catch::Matchers::WithinRel(2.75, 0.0001));

    intBuffer.insert(4);
    // Check the data in the buffer after insertion
    REQUIRE(intBuffer.getIndex(0) == 1);
    REQUIRE(intBuffer.getIndex(1)  == 2);
    REQUIRE(intBuffer.getIndex(2)  == 3);
    REQUIRE(intBuffer.getIndex(3)  == 5);
    REQUIRE(intBuffer.getIndex(4)  == 4);

    intBuffer.insert(99);

    intBuffer.displayBuffer();
    REQUIRE(intBuffer.getIndex(0) == 2);
    REQUIRE(intBuffer.getIndex(1)  == 3);
    REQUIRE(intBuffer.getIndex(2)  == 5);
    REQUIRE(intBuffer.getIndex(3)  == 4);
    REQUIRE(intBuffer.getIndex(4)  == 99);

    intBuffer.insert(72);
    REQUIRE(intBuffer.getIndex(0) == 3);
    REQUIRE(intBuffer.getIndex(1)  == 5);
    REQUIRE(intBuffer.getIndex(2)  == 4);
    REQUIRE(intBuffer.getIndex(3)  == 99);
    REQUIRE(intBuffer.getIndex(4)  == 72);

    REQUIRE_THAT(intBuffer.calculateAverage(), Catch::Matchers::WithinRel(36.6, 0.0001));
    //REQUIRE(true);

}

TEST_CASE( "Check float Buffer ", "" ) {

    CircularBuffer<float> floatBuffer(5);
    REQUIRE(floatBuffer.getMaxSize() == 5);
    // Insert data into the buffer
    floatBuffer.insert(1.1);
    floatBuffer.insert(2.2);
    floatBuffer.insert(3.3);
    floatBuffer.insert(5.5);
    std::cout<<floatBuffer.calculateAverage()<<std::endl;
    REQUIRE_THAT(floatBuffer.calculateAverage(), Catch::Matchers::WithinRel(3.025, 0.0001));

    floatBuffer.insert(4.4);
    // Check the data in the buffer after insertion
    REQUIRE(floatBuffer.getIndex(0) == 1.1f);
    REQUIRE(floatBuffer.getIndex(1)  == 2.2f);
    REQUIRE(floatBuffer.getIndex(2)  == 3.3f);
    REQUIRE(floatBuffer.getIndex(3)  == 5.5f);
    REQUIRE(floatBuffer.getIndex(4)  == 4.4f);

    floatBuffer.insert(99.9);

    floatBuffer.displayBuffer();
    REQUIRE(floatBuffer.getIndex(0) == 2.2f);
    REQUIRE(floatBuffer.getIndex(1)  == 3.3f);
    REQUIRE(floatBuffer.getIndex(2)  == 5.5f);
    REQUIRE(floatBuffer.getIndex(3)  == 4.4f);
    REQUIRE(floatBuffer.getIndex(4)  == 99.9f);

    floatBuffer.insert(72.8);
    REQUIRE(floatBuffer.getIndex(0) == 3.3f);
    REQUIRE(floatBuffer.getIndex(1)  == 5.5f);
    REQUIRE(floatBuffer.getIndex(2)  == 4.4f);
    REQUIRE(floatBuffer.getIndex(3)  == 99.9f);
    REQUIRE(floatBuffer.getIndex(4)  == 72.8f);

    REQUIRE_THAT(floatBuffer.calculateAverage(), Catch::Matchers::WithinRel(37.18, 0.0001));

}