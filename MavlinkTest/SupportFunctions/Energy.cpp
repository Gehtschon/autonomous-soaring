//
// Created by fabian on 24.12.23.
//

#include "Energy.h"

Energy::Energy(float energy) : Energyvalue(energy) {
    createtimestamp();
}

Energy::Energy() {}

void Energy::createtimestamp() {
    auto currentTime = std::chrono::system_clock::now();

    // Convert the time point to milliseconds since the epoch
    auto millisecondsSinceEpoch = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime.time_since_epoch());

    // Extract the current millisecond within the day
    auto millisecondsWithinDay = millisecondsSinceEpoch.count() % 86400000; // 86400000 milliseconds in a day

    time_Seconds = millisecondsWithinDay;
}




Energy Energy::operator+(const Energy& other) const {
    return Energy(Energyvalue + other.Energyvalue);
}

float Energy::getEnergyvalue() const {
    return Energyvalue;
}

void Energy::setEnergyvalue(float energyvalue) {
    createtimestamp();
    Energyvalue = energyvalue;
}

long Energy::getTimeSeconds() const {
    return time_Seconds;
}

void Energy::setTimeSeconds(long timeSeconds) {
    time_Seconds = timeSeconds;
}

Energy Energy::operator-(const Energy& other) const {
    return Energy(Energyvalue - other.Energyvalue);
}

Energy Energy::operator*(float scalar) const {
    return Energy(Energyvalue * scalar);
}

Energy Energy::operator/(float divisor) const {
    if (divisor != 0.0f) {
        return Energy(Energyvalue / divisor);
    } else {
        // Handle division by zero gracefully, you might want to throw an exception or handle it in some other way.
        // For simplicity, we return an Energy with a value of 0 in this example.
        return Energy(0.0f);
    }
}


bool Energy::operator==(const Energy& other) const {
    return Energyvalue == other.Energyvalue;
}

bool Energy::operator!=(const Energy& other) const {
    return !(Energyvalue == other.Energyvalue);
}

bool Energy::operator<(const Energy& other) const {
    return Energyvalue < other.Energyvalue;
}

bool Energy::operator<=(const Energy& other) const {
    return Energyvalue <= other.Energyvalue;
}

bool Energy::operator>(const Energy& other) const {
    return Energyvalue > other.Energyvalue;
}

bool Energy::operator>=(const Energy& other) const {
    return Energyvalue >= other.Energyvalue;
}

Energy& Energy::operator++() {
    ++Energyvalue;
    return *this;
}



Energy& Energy::operator--() {
    --Energyvalue;
    return *this;
}



Energy& Energy::operator+=(const Energy& other) {
    Energyvalue += other.Energyvalue;
    return *this;
}

Energy& Energy::operator-=(const Energy& other) {
    Energyvalue -= other.Energyvalue;
    return *this;
}

Energy& Energy::operator*=(float scalar) {
    Energyvalue *= scalar;
    return *this;
}

Energy& Energy::operator/=(float divisor) {
    if (divisor != 0.0f) {
        Energyvalue /= divisor;
    } else {
        // Handle division by zero gracefully, you might want to throw an exception or handle it in some other way.
        // For simplicity, we set the Energyvalue to 0 in this example.
        Energyvalue = 0.0f;
    }
    return *this;
}