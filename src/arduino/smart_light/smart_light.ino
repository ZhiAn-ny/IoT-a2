#include "Led.h"
#include "LightSensorImpl.h"
#include "PirSensor.h"

// the pin that must be used
#define LED_PIN_A 5
#define LED_PIN_B 12
#define LED_PIN_C 13
#define Pir_PIN 2
#define LS_PIN A1
#define S_ECHO_PIN 7
#define S_TRIG_PIN 8
#define POT_PIN A1

#define THl 500
LightExt* led;
LightSensor* lightSensor;
PirSensor* pirSensor;
int T1=3000;

enum { NORMAL, PRE_ALARM, ALARM} state;

void setup(){
  led = new Led(LED_PIN_A);  
  led->switchOff();
  lightSensor = new LightSensorImpl(LS_PIN);
  pir_sensor=new pirSensor(Pir_PIN);
  t=millis();
  state = NORMAL;
  Serial.begin(9600);
}

void loop(){
  int level = lightSensor->getLightIntensity();
  Serial.println(level);  
  if (level >THl || no_one_after_T1()==true){  //THl va da 0 a 1000
    led->switchOff();
  }else
    led->switchOn();
}

bool no_one_after_T1(){
  bool some_one_detected=pirSensor->detect();
  if (t>=T1 && some_one_detected==false )
    return true;
  else
    return false;
}
