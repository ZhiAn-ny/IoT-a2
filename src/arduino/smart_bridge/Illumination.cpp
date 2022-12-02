#include "Illumination.h"

using namespace bridge_control::illumination;
using namespace pins::led;

IlluminationSystem::IlluminationSystem() {}
IlluminationSystem::~IlluminationSystem() {}

void IlluminationSystem::init(Scheduler* sched)
{
    this->bridge_lights = new Led(bridge);

    this->smart_light_task = new SmartLightTask();
    this->smart_light_task->init(100);
    sched->addTask(this->smart_light_task);
}

void IlluminationSystem::turnOff()
{
    this->smart_light_task->setInactive();
    this->bridge_lights->switchOff();
}

void IlluminationSystem::turnOn()
{
    this->smart_light_task->setActive();
    //this->bridge_lights->switchOn();
}
