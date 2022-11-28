#include "UserInpuntEnableTask.h"

using namespace bridge_scheduling::tasks;

InputEnableTask::InputEnableTask(bool* enabled)
{
    this->enabled_ = enabled;
    this->button_ = new ButtonImpl(BUTTON_PIN);
}

void InputEnableTask::init(int period)
{
    Task::init(period);
}

void InputEnableTask::tick()
{
    if (this->button_->isPressed()) {
        Serial.println("Click!");
        *this->enabled_ = !(*this->enabled_);
        
    }

}

