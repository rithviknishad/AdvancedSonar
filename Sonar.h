/*
Name:       Sonar.h
Author:     Rithvik Nishad (github.com/rithviknishad)
License:    GNU General Public License v3.0

Description:
    Sonar library allows users to handle multiple sonar sensors with minimal
    code and also supports up to 65,536 sonar sensors in just two IO pins.
*/

#ifndef __ULTRASONIC_H
#define __ULTRASONIC_H

#include "Arduino.h"

#define units_cm    28
#define units_inch  71

#ifndef DEFAULT_ULTRASONIC_REPORTING_UNIT
#define DEFAULT_ULTRASONIC_REPORTING_UNIT units_cm
#endif

class Sonar
{
protected:
    volatile uint8_t* Trigger;
    const uint8_t TriggerBit, Echo;

public:
    float Offset, MaxTimeout;

public:
    Sonar(int trigPin, int echoPin, float offset = 0, float MaxDistance = -1);

protected:
    void performTrigger() const;
    float getDistance() const;

public:
    float Scan() const;

    operator float() const { return Scan(); }
    operator int()   const { return Scan(); }
};

template<size_t S>
class SonarArray : protected Sonar
{
public:
    float Distances[S];

    SonarArray(uint8_t trigPin, uint8_t echoPin);
    float Scan();

};

template<size_t S>
inline SonarArray<S>::SonarArray(uint8_t trigPin, uint8_t echoPin)
    : Sonar(trigPin, echoPin, 0, -1)
{
}

template<size_t S>
inline float SonarArray<S>::Scan()
{
    performTrigger();

    for (size_t i = 0; i < S; ++i)
        Distances[i] = getDistance();

    return Distances[0];
}
#endif
