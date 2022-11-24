#include "PirSensor.h"
#include "Arduino.h"
PirSensor::PirSensor(int pin){
  this->pin = pin;
}

bool PirSensor::detect(){
  int detected = digitalRead(pin);
  if (detected == HIGH){
    Serial.println("some one detected!");
    return true;
  }else{
    Serial.println("no body detected!");
     return false;
  }
}
