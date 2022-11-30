#include "BridgeValve.h"

using namespace bridge_control::bridge_valve;
using namespace bridge_scheduling::tasks;

void BridgeValve::init(Scheduler* sched, float* water_level)
{
    this->valve_.attach();
    this->regulate_on_water_level = new RegulateValveTask(&this->valve_, water_level);
    this->regulate_on_water_level->init(sampling_periods::pe_alarm);
    this->regulate_on_water_level->setActive();
    sched->addTask(this->regulate_on_water_level);

    int degrees = this->valve_.get_opening_degrees();
    this->valve_.open_valve(degrees);

    this->is_auto_ = false;
    
    Serial.print("Valve initial opening degrees: ");
    Serial.println(degrees);
}

void BridgeValve::activate()
{
    this->regulate_on_water_level->setActive();
    Serial.println("Valve activated");
    this->valve_.attach();
    this->is_auto_ = true;
}

void BridgeValve::deactivate()
{
    this->regulate_on_water_level->setInactive();
    Serial.println("Valve deactivated");
    this->valve_.detach();

    this->is_auto_ = false;
}

bool BridgeValve::is_auto()
{
    return this->is_auto_;
}

void BridgeValve::open_valve(int degrees)
{
    this->valve_.open_valve(degrees);
}

int BridgeValve::get_opening_degrees()
{
    return this->valve_.get_opening_degrees();
}
