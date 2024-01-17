//
// Created by fabian on 24.12.23.
//

#ifndef AUTONOMOUS_SOARING_ENERGY_H
#define AUTONOMOUS_SOARING_ENERGY_H

#include <iostream>
#include <chrono>
#include <ctime>
class Energy {
private:
    float Energyvalue;
    //current time of the day in seconds
    std::chrono::milliseconds::rep time_MilliSeconds;
    // position
    int32_t lat;
    int32_t lon;
    void createtimestamp();
public:
    explicit Energy(float energy);
    explicit Energy(float energy, int32_t lat, int32_t lon);

    Energy();


    // Overload arithmetic operators
    Energy operator+(const Energy& other) const;
    Energy operator-(const Energy& other) const;
    Energy operator*(float scalar) const;
    Energy operator/(float divisor) const;

    // Overload comparison operators
    bool operator==(const Energy& other) const;
    bool operator!=(const Energy& other) const;
    bool operator<(const Energy& other) const;
    bool operator<=(const Energy& other) const;
    bool operator>(const Energy& other) const;
    bool operator>=(const Energy& other) const;

    // Overload increment and decrement operators
    Energy& operator++();    // Prefix increment
    Energy& operator--();    // Prefix decrement

    // Overload assignment operators
    Energy& operator+=(const Energy& other);
    Energy& operator-=(const Energy& other);
    Energy& operator*=(float scalar);
    Energy& operator/=(float divisor);

    float getEnergyvalue() const;

    void setEnergyvalue(float energyvalue);

    long getTimeMilliSeconds() const;

    void setTimeMilliSeconds(long timeSeconds);

    int32_t getLat() const;

    void setLat(int32_t lat);

    int32_t getLon() const;

    void setLon(int32_t lon);

};


#endif //AUTONOMOUS_SOARING_ENERGY_H
