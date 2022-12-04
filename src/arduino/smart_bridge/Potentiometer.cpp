#include "Potentiometer.h"

Potentiometer::Potentiometer(int pin)
{
    pinMode(pin, INPUT);
    this->pin_ = pin;
}
Potentiometer::~Potentiometer()
{

}

int Potentiometer::read()
{
    return analogRead(this->pin_);
}
