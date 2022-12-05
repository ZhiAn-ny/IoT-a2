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

    bool press = this->button_->isPressed();

    if (press && !(this->prev_btn_val_ == press)) {
        *this->enabled_ = !(*this->enabled_);
        Serial.println("Click");
    }
    
    this->prev_btn_val_ = press;
    
}

