#include "UserInpuntEnableTask.h"

using namespace bridge_scheduling::tasks;
using namespace pins;

InputEnableTask::InputEnableTask(Task* manual_input_task, Task* auto_reg)
{
    this->auto_reg_ = auto_reg;
    this->manual_input_task_ = manual_input_task;
    this->manual_input_task_->setInactive();
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

        if (this->manual_input_task_->isActive()) {
            this->auto_reg_->setActive();
            this->manual_input_task_->setInactive();
            Serial.println("MODE:AUTO");
        } else {
            this->auto_reg_->setInactive();
            this->manual_input_task_->setActive();
            Serial.println("MODE:MANUAL");
        }
        
    }
    
    this->prev_btn_val_ = press;
    
}

