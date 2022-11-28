#include "UserInputHandler.h"

using namespace bridge_control::user_input;
using namespace bridge_scheduling::tasks;

UserInputHandler::UserInputHandler() {}
UserInputHandler::~UserInputHandler() {}

bool UserInputHandler::isEnabled()
{
    return this->enabled_;
}

void UserInputHandler::init(Scheduler* sched)
{
    this->button_pressed_task_ = new InputEnableTask(&this->enabled_);
    this->button_pressed_task_->init(100);
    sched->addTask(this->button_pressed_task_);
}
