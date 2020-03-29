#include "Sonar.h"

Sonar::Sonar(int trigPin, int echoPin, float offset, float MaxDistance)
    : TriggerBit(digitalPinToBitMask(trigPin)), Echo(echoPin), Offset(offset)
{
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    Trigger = portOutputRegister(digitalPinToPort(trigPin));
    MaxTimeout = ((MaxDistance < 0) ? 20000UL : (MaxDistance * DEFAULT_ULTRASONIC_REPORTING_UNIT * 2));
}

void Sonar::performTrigger() const
{
    *Trigger &= ~TriggerBit;
    delayMicroseconds(2);

    *Trigger |= TriggerBit;
    delayMicroseconds(10);
    *Trigger &= ~TriggerBit;
}

float Sonar::getDistance() const {
    return pulseIn(Echo, HIGH, MaxTimeout) / DEFAULT_ULTRASONIC_REPORTING_UNIT / 2; 
}

float Sonar::Scan() const
{
    performTrigger();
    return getDistance();
}