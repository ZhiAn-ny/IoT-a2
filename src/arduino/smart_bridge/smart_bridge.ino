#include <Arduino.h>

#include "Scheduler.h"
#include "SmartLightTask.h"

#include "WaterMonitor.h"
#include "Illumination.h"
#include "UserInputHandler.h"
#include "Lcd.h"

using namespace bridge_control::water_monitor;
using namespace bridge_control::illumination;
using namespace bridge_control::user_input;


Scheduler sched;

WaterMonitorController water_monitor;
IlluminationSystem bridge_lights;
UserInputHandler user_input;



void setup() {

  Serial.begin(19200);
  Serial.println("Welcome to Smart Bridge Project");

  sched.init(100);


 // user_input.init(&sched);
  water_monitor.init(&sched);
  bridge_lights.init(&sched);

}

void loop() {
  sched.schedule();
  
  water_monitor.loop();

  if (water_monitor.is_in_alarm_state()) {
    bridge_lights.turnOff();
    
    // TODO: valve open by a degrees which depends on water level, etc.
  } else {
    bridge_lights.turnOn();
  }

}
