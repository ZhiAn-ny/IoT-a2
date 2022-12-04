#include "Potentiometer.h"
#include "Arduino.h"

Potentiometer::Potentiometer(int pin) {
	this->pin = pin;
}

int Potentiometer::pot_value() {
	int current;
	int newValue = analogRead(this->pin);
	if (newValue != current) {
		current = newValue;
	}
	return current;
}