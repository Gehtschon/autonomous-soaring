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
    std::chrono::milliseconds::rep time_Seconds;
    void createtimestamp();
public:
    explicit Energy(float energy);

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

    long getTimeSeconds() const;

    void setTimeSeconds(long timeSeconds);

};


#endif //AUTONOMOUS_SOARING_ENERGY_H
