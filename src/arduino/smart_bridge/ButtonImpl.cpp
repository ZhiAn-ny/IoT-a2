#include "ButtonImpl.h"
#include "Arduino.h"

ButtonImpl::ButtonImpl(int pin){
  this->pin = pin;
  pinMode(pin, INPUT_PULLUP);     
} 
  
bool ButtonImpl::isPressed(){
  int value = digitalRead(pin);
  return value == LOW;
}


