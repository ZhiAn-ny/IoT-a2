#include "Led.h"
#include "LightSensorImpl.h"

// the pin must by a PWM one
#define LED_PIN_A 5
#define Pir_PIN 2
#define LS_PIN A1
#define THl 500
LightExt* led;
LightSensor* lightSensor;


void setup(){
  led = new Led(LED_PIN_A);  
  led->switchOff();
  lightSensor = new LightSensorImpl(LS_PIN);
  pir_sensor=new pirSensor(Pir_PIN);
  Serial.begin(9600);
}

void loop(){
  int level = lightSensor->getLightIntensity();
  Serial.println(level);  
  if (level < THl){
    led->switchOn();;
  }else
    led->switchOff();
};
