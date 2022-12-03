/* supponendo di eseguire il test 
   in un ambiente a 20 °C 
   https://it.wikipedia.org/wiki/Velocità_del_suono
   */
#include "Sonar.h"

//#define DEBUG

using namespace pins::sonar;

const float vs = 331.45 + 0.62*20;

Sonar::Sonar(int trigPin, int echoPin){
  this->trigPin = trigPin;
  this->echoPin = echoPin;

  this->newSonar = new NewPing(trigPin, echoPin, max_distance);
}

float Sonar::getDistance(){
  long duration, distance;

  duration = this->newSonar->ping();
  distance = microsec_to_cm(duration);

#ifdef DEBUG
  Serial.print("Duration: "); Serial.print(duration); 
  Serial.print(" distance: "); Serial.println(distance);
#endif //!DEBUG

  if (distance >= max_distance || duration == 0) {
    // the target is too far, the sound is not coming back
    return max_distance;
  }
  if (distance <= 0) {
    return 0;
  }

  return distance;
}

float Sonar::microsec_to_cm(float microsec)
{
  return (microsec / 29 / 2);
}
