#include "WaterMonitor.h"

using namespace bridge_control::water_monitor;
using namespace pins;

WaterMonitorController::WaterMonitorController() {}
WaterMonitorController::~WaterMonitorController() {}

void WaterMonitorController::init_lights(int green, int red)
{
    this->green_ = new Led(green);
    this->red_ = new Led(red);
}

void WaterMonitorController::set_tasks(Scheduler* sched)
{
    this->led_blink_task_ = new BlinkTask(led::red);
    this->led_blink_task_->init(2000); // blink every 2 seconds
    this->led_blink_task_->setInactive();
    sched->addTask(this->led_blink_task_);

    this->water_sampling_task_ = new WaterSamplingTask(&this->water_surface_dist_);
    sched->addTask(this->water_sampling_task_);
}

void WaterMonitorController::init_display()
{
  this->display_.init();
}

void WaterMonitorController::init(Scheduler* sched)
{
    this->init_lights(led::green, led::red);
    this->set_tasks(sched);
    this->init_display();
    this->loop();
}

SystemState WaterMonitorController::get_system_state()
{
    if (this->water_surface_dist_ > this->water_level_1_) {
        return SystemState::Normal;
    } else if (this->water_surface_dist_ > this->water_level_2_) {        
        return SystemState::PreAlarm;
    } else if (this->water_surface_dist_ > this->water_level_max_) {
        return SystemState::Alarm;
    }

    return SystemState::Undefined;
}

void WaterMonitorController::set_system_state_normal()
{
    this->green_->switchOn();
    this->red_->switchOff();

    this->water_sampling_task_->init(this->pe_normal_);
    this->led_blink_task_->setInactive();

    this->state_ = SystemState::Normal;
}

void WaterMonitorController::set_system_state_prealarm()
{
    this->display_.print_pre_alarm();

    this->green_->switchOn();
    this->led_blink_task_->setActive();
    
    this->water_sampling_task_->init(this->pe_prealarm_);

    this->state_ = SystemState::PreAlarm;
}

void WaterMonitorController::set_system_state_alarm()
{
    this->led_blink_task_->setInactive();

    this->red_->switchOn();
    this->green_->switchOff();

    this->water_sampling_task_->init(this->pe_alarm_);

    this->state_ = SystemState::Alarm;
}

void WaterMonitorController::update_state()
{
    SystemState new_state = this->get_system_state();

    if (this->state_ == new_state) return;

    switch (new_state)
    {
        case SystemState::Normal:
            this->set_system_state_normal();
        break;
        case SystemState::PreAlarm:
            this->set_system_state_prealarm();
        break;
        case SystemState::Alarm:
            this->set_system_state_alarm();
        break;
        case SystemState::Undefined:
        break;
    }
}

void WaterMonitorController::loop()
{
    this->update_state();
    this->handle_current_state();
}

void WaterMonitorController::handle_current_state()
{
    switch (this->state_)
    {
        case SystemState::Normal:
            this->display_.clear();


        break;
        case SystemState::PreAlarm:
            this->display_.print_water_distance(this->water_surface_dist_);


        break;
        case SystemState::Alarm:


        break;
        case SystemState::Undefined:
        break;
    }
}

bool WaterMonitorController::is_in_alarm_state()
{
    return this->state_ == SystemState::Alarm;
}
