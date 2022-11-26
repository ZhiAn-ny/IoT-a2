#include <Arduino.h>
#include "Scheduler.h"
#include "SmartLightTask.h"

#include "tasks/BlinkTask.h"

using namespace bridge_scheduling;

Scheduler sched;


void setup(){

  Serial.begin(9600);
  Serial.println("Welcome to Smart Bridge Project");

  sched.init(100);
  Serial.println("Scheduler initialized");
 
  Task* test = new tasks::BlinkTask(LED_PIN_B);
  test->init(1000);
  Serial.println("Task created");
  sched.addTask(test);

  Serial.println("Ready");

  // Task* t0 = new SmartLightTask();
  // t0->init(100);
  // Serial.println("Task initialized");

  // sched.addTask(t0);
  // Serial.println("Task added to scheduler");
   
}

void loop(){
  sched.schedule();
}
