#include <Arduino.h>

#include "Scheduler.h"
#include "SmartLightTask.h"

#include "BlinkTask.h"

#include "WaterMonitor.h"
#include "Illumination.h"

using namespace bridge_control::water_monitor;
using namespace bridge_control::illumination;


Scheduler sched;

WaterMonitorController water_monitor;
IlluminationSystem bridge_lights;


void setup() {

  Serial.begin(19200);
  Serial.println("Welcome to Smart Bridge Project");

  sched.init(100);

  water_monitor.init(&sched);
  bridge_lights.init(&sched);

}

void loop() {
  sched.schedule();

  water_monitor.handle_current_state();

  if (water_monitor.is_in_alarm_state()) {
    bridge_lights.turnOff();
    
    // TODO: valve open by a degrees which depends on water level, etc.
  }

}
