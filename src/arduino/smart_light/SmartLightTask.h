#ifndef __SMARTLIGHTTASK__
#define __SMARTLIGHTTASK__
#include "Led.h"
#include "Task.h"
#include "config.h"
#include "LightSensor.h"
#include "PirSensor.h"
#include "PirSensor.h"

class SmartLightTask: public Task {

  Led* led;
  LightSensor* lightSensor;
  PirSensor* pirSensor;
  int t, T1=3000;

public:
  SmartLightTask();  
  void init(int period);  
  void tick();
};

#endif
