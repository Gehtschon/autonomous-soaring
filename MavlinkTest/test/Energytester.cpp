//
// Created by fabian on 24.12.23.
//
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include "CircularBuffer.h"

#include "DataDistributor.h"


#include "Energy.h"

TEST_CASE("Test Energy Operators", "[Energy]") {
    SECTION("Test Addition Operator") {
        Energy energy1(5.0);
        Energy energy2(3.0);

        Energy result = energy1 + energy2;

        REQUIRE(result.getEnergyvalue() == 8.0);
    }

    SECTION("Test Subtraction Operator") {
        Energy energy1(5.0);
        Energy energy2(3.0);

        Energy result = energy1 - energy2;

        REQUIRE(result.getEnergyvalue() == 2.0);
    }

    SECTION("Test Multiplication Operator") {
        Energy energy(5.0);
        float scalar = 2.0;

        Energy result = energy * scalar;

        REQUIRE(result.getEnergyvalue() == 10.0);
    }

    SECTION("Test Division Operator") {
        Energy energy(6.0);
        float divisor = 2.0;

        Energy result = energy / divisor;

        REQUIRE(result.getEnergyvalue() == 3.0);
    }

    SECTION("Test Equality Operator") {
        Energy energy1(5.0);
        Energy energy2(5.0);

        REQUIRE(energy1 == energy2);
    }

    SECTION("Test Inequality Operator") {
        Energy energy1(5.0);
        Energy energy2(3.0);

        REQUIRE(energy1 != energy2);
    }

    SECTION("Test Less Than Operator") {
        Energy energy1(3.0);
        Energy energy2(5.0);

        REQUIRE(energy1 < energy2);
    }

    SECTION("Test Less Than or Equal Operator") {
        Energy energy1(3.0);
        Energy energy2(3.0);

        REQUIRE(energy1 <= energy2);
    }

    SECTION("Test Greater Than Operator") {
        Energy energy1(5.0);
        Energy energy2(3.0);

        REQUIRE(energy1 > energy2);
    }

    SECTION("Test Greater Than or Equal Operator") {
        Energy energy1(5.0);
        Energy energy2(5.0);

        REQUIRE(energy1 >= energy2);
    }

    SECTION("Test Prefix Increment Operator") {
        Energy energy(5.0);

        ++energy;
        std::cout << energy.getTimeSeconds() << std::endl;
        REQUIRE(energy.getEnergyvalue() == 6.0);
    }

    SECTION("Test Prefix Decrement Operator") {
        Energy energy(5.0);

        --energy;

        REQUIRE(energy.getEnergyvalue() == 4.0);
    }

    SECTION("Test Compound Assignment Operators") {
        Energy energy1(5.0);
        Energy energy2(3.0);

        energy1 += energy2;
        REQUIRE(energy1.getEnergyvalue() == 8.0);

        energy1 -= energy2;
        REQUIRE(energy1.getEnergyvalue() == 5.0);

        energy1 *= 2.0;
        REQUIRE(energy1.getEnergyvalue() == 10.0);

        std::cout << energy1.getTimeSeconds() << std::endl;
        energy1 /= 2.0;
        REQUIRE(energy1.getEnergyvalue() == 5.0);
    }

    // Testing of the position data in the energy objects
    SECTION("Test Position Data") {
        Energy energy1(5.0,45,-45);
        Energy energy2(3.0,60,61);

        REQUIRE(energy1.getLat() == 45);
        REQUIRE(energy1.getLon() == -45);
        REQUIRE(energy2.getLat() == 60);
        REQUIRE(energy2.getLon() == 61);

        energy1.setLat(50);
        energy1.setLon(-50);
        REQUIRE(energy1.getLat() == 50);
        REQUIRE(energy1.getLon() == -50);

    }


}