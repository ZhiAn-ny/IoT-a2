#include "UserInpuntEnableTask.h"

using namespace bridge_scheduling::tasks;
using namespace pins;

InputEnableTask::InputEnableTask(bool* enabled)
{
    this->enabled_ = enabled;
    this->button_ = new ButtonImpl(user_input::btn);
}

void InputEnableTask::init(int period)
{
    Task::init(period);
}

void InputEnableTask::tick()
{
    if (!this->isActive()) return;

    if (this->button_->isPressed()) {
        *this->enabled_ = !(*this->enabled_);
        Serial.println("Click");
    }
}

