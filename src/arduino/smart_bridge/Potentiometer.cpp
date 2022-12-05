#include "Potentiometer.h"

Potentiometer::Potentiometer(int pin) {
    pinMode(pin, INPUT);
	this->pin = pin;
}

int Potentiometer::pot_value() {
	int newValue = analogRead(this->pin);
	if (newValue != current) {
		this->current = newValue;
	}
	return current;
}
