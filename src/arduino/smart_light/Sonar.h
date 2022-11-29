#ifndef __SONAR__ 
#define __SONAR__

#include <Arduino.h>
#include <NewPing.h>
#include "config.h"

#define TRIG 6
#define ECHO 7
#define MAX_DISTANCE 200

class Sonar {
public:
  Sonar(int trigPin, int echoPin);
  float getDistance();  

protected:
  int echoPin;
  int trigPin;  

private:
  NewPing* newSonar;
  float microsec_to_cm(float microsec);
};

#endif
