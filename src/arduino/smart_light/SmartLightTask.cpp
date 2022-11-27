#include "SmartLightTask.h"

SmartLightTask::SmartLightTask(){
  
}
  
void SmartLightTask::init(int period){
  Task::init(period);
  led = new Led(LED_PIN_A);  
  led->switchOff();
  lightSensor = new LightSensorImpl(LS_PIN);
  pirSensor=new PirSensor(Pir_PIN); 
}
  
void SmartLightTask::tick() {
  if (!this->isActive()) return;

  int light_intensity = lightSensor->getLightIntensity();

#ifdef DEBUG
  Serial.print("Light level: ");
  Serial.println(light_intensity);
#endif // !DEBUG

  if (light_intensity > THl) {
    // There is enough light, we do not need to turn the led on
      led->switchOff();
      return;
  }

  if(pirSensor->detect() == true ){
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
