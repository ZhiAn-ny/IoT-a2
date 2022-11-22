#include "PirSensor.h"
#include "Arduino.h"
PirSensor::PirSensor(int pin){
  this->pin = pin;
}

bool PirSensor::detect(){
  int detected = digitalRead(pin);
  if (detected == HIGH){
    Serial.println("person detected!");
    return true
  }else
    return false;
}
