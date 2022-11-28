#ifndef __SONAR__ 
#define __SONAR__

#include <Arduino.h>
#include <NewPing.h>
#include "config.h"

#define MAX_DISTANCE 200

class Sonar {
public:
  Sonar(int trigPin, int echoPin);
  float getDistance();  

protected:
  // in
  int echoPin;
  // out
  int trigPin;  

private:
  NewPing* newSonar = new NewPing(S_TRIG_PIN, S_ECHO_PIN, MAX_DISTANCE); 
  float microsec_to_cm(float microsec);
};
#endif
