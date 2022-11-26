#ifndef __CONFIG__ 
#define __CONFIG__

#include <Arduino.h>
#include <LiquidCrystal_I2C.h> 

#include "Led.h"
#include "Sonar.h"
#include "Motor.h"
#include "ButtonImpl.h"
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
#define BUTTON_PIN 11
#define POT_PIN A0
#define THl 18

#endif // !__CONFIG__
