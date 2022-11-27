#include "BlinkTask.h"

using namespace bridge_scheduling::tasks;

BlinkTask::BlinkTask(int pin)
{
    this->pin_ = pin;
}

void BlinkTask::init(int period)
{
    Task::init(period);
    this->led_ = new Led(this->pin_);
    this->state_ = OFF;
}

void BlinkTask::tick()
{
    if (!this->isActive()) return;
    
    if (this->state_ == ON) {
        this->led_->switchOff();
        this->state_ = OFF;
    } else {
        this->led_->switchOn();
        this->state_ = ON;
    }
}
