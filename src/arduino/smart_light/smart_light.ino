#include <Arduino.h>

#include "Scheduler.h"
#include "SmartLightTask.h"

#include "BlinkTask.h"

#include "WaterMonitor.h"

using namespace bridge_control::water_monitor;


Scheduler sched;

WaterMonitorController controller;


void setup(){

  Serial.begin(19200);
  Serial.println("Welcome to Smart Bridge Project");

  sched.init(100);

  controller.init(&sched);

  Task* t0 = new SmartLightTask();
  t0->init(100);
  sched.addTask(t0);
   if (Serial.availableForWrite()) {
    Serial.println(sched.getTasksCount());
  }
}

void loop(){
  sched.schedule();

  controller.handle_current_state();

  // if (controller.is_in_alarm_state()) {
  //   // TODO: turn off lighting subsystem (led a)
  //   // valve open by a degrees which depends on water level, etc.
  // }

}
