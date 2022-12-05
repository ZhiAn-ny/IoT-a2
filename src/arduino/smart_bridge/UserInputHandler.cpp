#include "UserInputHandler.h"

using namespace bridge_control::user_input;
using namespace bridge_scheduling::tasks;

UserInputHandler::UserInputHandler() {}
UserInputHandler::~UserInputHandler() {}

bool UserInputHandler::isEnabled()
{
    return this->enabled_;
}

void UserInputHandler::init(Scheduler* sched, Motor* valve)
{
    this->command_valve_ = new ManualValveControlTask();

    this->input_enable_task_ = new InputEnableTask(&this->enabled_);
    this->input_enable_task_->init(100);
    sched->addTask(this->input_enable_task_);

    Serial.println("Init ui handler");
}

void UserInputHandler::disable()
{
    this->input_enable_task_->setInactive();
}

void UserInputHandler::enable()
{
    this->input_enable_task_->setActive();
}
