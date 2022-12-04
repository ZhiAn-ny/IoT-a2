/* supponendo di eseguire il test 
   in un ambiente a 20 °C 
   https://it.wikipedia.org/wiki/Velocità_del_suono
   */
#include "Sonar.h"

using namespace pins::sonar;

const float vs = 331.45 + 0.62*20;

Sonar::Sonar(int trigPin, int echoPin){
  this->trigPin = trigPin;
  this->echoPin = echoPin;

#ifdef USE_NEW_PING
  this->newSonar = new NewPing(trigPin, echoPin, max_distance);
#else
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
#endif // !USE_NEW_PING
}

float Sonar::getDistance(){
  long duration, distance;

#ifdef USE_NEW_PING
  duration = this->newSonar->ping();
  distance = microsec_to_cm(duration);
#else
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  //distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  distance = microsec_to_cm(duration);
#endif

#ifdef DEBUG_SONAR
  Serial.print("Duration: "); Serial.print(duration); 
  Serial.print(" distance: "); Serial.println(distance);
#endif //!DEBUG_SONAR

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
