/* supponendo di eseguire il test 
   in un ambiente a 20 °C 
   https://it.wikipedia.org/wiki/Velocità_del_suono
   */
#include "Sonar.h"

const float vs = 331.45 + 0.62*20;

Sonar::Sonar(int trigPin, int echoPin){
  this->trigPin = trigPin;
  this->echoPin = echoPin;
}

float Sonar::getDistance(){
  long duration, distance;

  duration = this->newSonar->ping();
  // Serial.print("ms: ");
  // Serial.println(duration);

  distance = microsec_to_cm(duration);
  // Serial.print("cm: ");
  // Serial.println(distance);

  if (distance >= MAX_DISTANCE || distance <= 0) {
    return MAX_DISTANCE;
  }

  return distance;
}

float Sonar::microsec_to_cm(float microsec)
{
  return (microsec / 29 / 2);
}
