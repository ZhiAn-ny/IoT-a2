#include "SmartLightTask.h"

// #define DEBUG

SmartLightTask::SmartLightTask(){
  
}
  
void SmartLightTask::init(int period){
  Task::init(period);
  led = new Led(led::bridge);  
  led->switchOff();
  lightSensor = new LightSensorImpl(ls::ls);
  pirSensor=new PirSensor(pir::pir); 
}
  
void SmartLightTask::tick() {
  if (!this->isActive()) return;

  unsigned int light_intensity = lightSensor->getLightIntensity();
  bool has_detected_somebody = pirSensor->detect();

#ifdef DEBUG
  Serial.print("Light level: ");
  Serial.print(light_intensity);
  Serial.print(" | detected: ");
  Serial.println(has_detected_somebody);
#endif // !DEBUG

  if (light_intensity > ls::THl) {
    // There is enough light, we do not need to turn the led on
      led->switchOff();
      return;
  }

  if(has_detected_somebody){
    // Someone is passing on the bridge
    led->switchOn();
    t = millis();
  }

  int now = millis();
  if (now - t > T1) {
    // Timeout elapsed, turn the led off
    led->switchOff();
  }
}
