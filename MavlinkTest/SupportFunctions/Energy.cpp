//
// Created by fabian on 24.12.23.
//

#include "Energy.h"

Energy::Energy(float energy, int32_t lat, int32_t lon) {
    Energyvalue = energy;
    this->lat = lat;
    this->lon = lon;
    createtimestamp();
}

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

    time_MilliSeconds = millisecondsWithinDay;
}


int32_t Energy::getLat() const {
    return lat;
}

void Energy::setLat(int32_t lat) {
    Energy::lat = lat;
}

int32_t Energy::getLon() const {
    return lon;
}

void Energy::setLon(int32_t lon) {
    Energy::lon = lon;
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

long Energy::getTimeMilliSeconds() const {
    return time_MilliSeconds;
}

void Energy::setTimeMilliSeconds(long timeSeconds) {
    time_MilliSeconds = timeSeconds;
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
        //Hanlde division by zero dont use exception. Just returning 0
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
        //Hanlde division by zero dont use exception. Just returning 0
        Energyvalue = 0.0f;
    }
    return *this;
}