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
  
void SmartLightTask::tick(){
   int level = lightSensor->getLightIntensity();
   Serial.println(level);   
    if(pirSensor->detect()==true ){
    if (level <=THl){
      led->switchOn();
      t=millis();
    }else{
      led->switchOff();
    }
  }
  }
