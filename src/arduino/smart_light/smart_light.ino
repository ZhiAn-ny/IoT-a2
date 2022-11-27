#include <Arduino.h>

#include "Scheduler.h"
#include "SmartLightTask.h"

#include "BlinkTask.h"

#include "WaterMonitor.h"

using namespace bridge_control::water_monitor;


Scheduler sched;

WaterMonitorController controller;


void setup(){

  Serial.begin(115200);
  Serial.println("Welcome to Smart Bridge Project");

  controller.init(&sched);

  // sched.init(100);
  // Serial.println("Scheduler initialized");
 
  // Task* test = new tasks::BlinkTask(LED_PIN_B);
  // test->init(1000);
  // Serial.println("Task created");
  // sched.addTask(test);


  Task* t0 = new SmartLightTask();
  t0->init(100);

  sched.addTask(t0);
   
}

void loop(){
  sched.schedule();

  controller.handle_current_state();

  if (controller.is_in_alarm_state()) {
    // TODO: turn off lighting subsystem (led a)
    // valve open by a degrees which depends on water level, etc.
  }

}
