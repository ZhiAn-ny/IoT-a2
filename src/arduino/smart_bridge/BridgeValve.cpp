#include "BridgeValve.h"

using namespace bridge_control::water_monitor;
using namespace bridge_scheduling::tasks;

void BridgeValve::init(Scheduler* sched, float* water_level)
{
    this->valve_ = new Motor();

    this->regulate_on_water_level = new RegulateValveTask(this->valve_, water_level);
    this->regulate_on_water_level->init(sampling_periods::pe_alarm);
    sched->addTask(this->regulate_on_water_level);

    this->user_input_ = new UserInputHandler();
    this->user_input_->init(sched, this->valve_, this->regulate_on_water_level);

    this->is_auto_ = true;
    this->deactivate();
}

void BridgeValve::activate()
{
    if (this->regulate_on_water_level->isActive()) return;

    this->valve_->attach();
    this->user_input_->enable();

    this->regulate_on_water_level->setActive();
    Serial.println("Valve activated");

    this->is_auto_ = true;
    this->is_active_ = true;
}

void BridgeValve::deactivate()
{
    if (!this->regulate_on_water_level->isActive()) return;
    
    this->valve_->detach();
    this->user_input_->disable();

    this->regulate_on_water_level->setInactive();
    Serial.println("Valve deactivated");


    this->is_auto_ = false;
    this->is_active_ = false;
}

bool BridgeValve::is_auto()
{
    return this->is_auto_;
}

int BridgeValve::get_opening_degrees()
{
    return this->valve_->get_opening_degrees();
}
