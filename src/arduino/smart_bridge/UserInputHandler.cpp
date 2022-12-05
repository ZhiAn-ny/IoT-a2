#include "UserInputHandler.h"

using namespace bridge_control::user_input;
using namespace bridge_scheduling::tasks;

UserInputHandler::UserInputHandler() {}
UserInputHandler::~UserInputHandler() {}

bool UserInputHandler::isEnabled()
{
    return this->enabled_;
}

void UserInputHandler::init(Scheduler* sched, Motor* valve, Task* auto_reg)
{
    this->manual_cmd_task_ = new ManualValveControlTask(valve);
    this->manual_cmd_task_->init(100);
    this->manual_cmd_task_->setInactive();
    sched->addTask(this->manual_cmd_task_);

    this->input_enable_task_ = new InputEnableTask(this->manual_cmd_task_, auto_reg);
    this->input_enable_task_->init(100);
    sched->addTask(this->input_enable_task_);
}

void UserInputHandler::disable()
{
    this->input_enable_task_->setInactive();
    this->manual_cmd_task_->setInactive();
}

void UserInputHandler::enable()
{
    this->input_enable_task_->setActive();
}
