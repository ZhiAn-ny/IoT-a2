#include <Arduino.h>

#include "Scheduler.h"
#include "SmartLightTask.h"

#include "BlinkTask.h"

#include "WaterMonitor.h"

using namespace bridge_scheduling;

Scheduler sched;




void setup(){

  Serial.begin(115200);
  Serial.println("Welcome to Smart Bridge Project");

  //controller.init();

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
}
