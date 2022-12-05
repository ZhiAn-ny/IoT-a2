#include "ManualValveControlTask.h"

using namespace bridge_scheduling::tasks;

ManualValveControlTask::ManualValveControlTask(Motor* valve)
{
    this->valve_ = valve;
    this->pot_ = new Potentiometer(pins::user_input::pot);
}

void ManualValveControlTask::init(int period)
{
    Task::init(period);
}

void ManualValveControlTask::tick()
{
    if (!this->isActive()) return;

    int pot_value = this->pot_->pot_value();
    int deg = map(pot_value, 0, 1024, 0, 181);

    this->valve_->open_valve(deg);
}

