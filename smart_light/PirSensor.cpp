#include "pirSensor.h"
#include "Arduino.h"
PirSensor::PirSensor(int pin){
  this->pin = pin;
}

int PirSensor::detect(){
  int detected = digitalRead(pin);
  if (detected == HIGH)
    Serial.println("person detected!");
}
