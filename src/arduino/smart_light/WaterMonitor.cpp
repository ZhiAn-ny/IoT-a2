#include "WaterMonitor.h"

using namespace bridge_control::water_monitor;

WaterMonitorController::WaterMonitorController() {}
WaterMonitorController::~WaterMonitorController() {}

void WaterMonitorController::init_lights(int green, int red)
{
    this->green_ = new Led(green);
    this->red_ = new Led(red);
}

void WaterMonitorController::init(Scheduler* sched)
{
    this->init_lights(LED_PIN_B, LED_PIN_C);

    this->water_sampling_task_ = new WaterSamplingTask(&this->water_surface_dist_);
    this->led_blink_task_ = new BlinkTask(LED_PIN_B);
    this->led_blink_task_->init(2000); // blink every 2 seconds
    this->led_blink_task_->setInactive();

    sched->addTask(this->water_sampling_task_);
    sched->addTask(this->led_blink_task_);

    this->handle_current_state();
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
}

void WaterMonitorController::set_system_state_normal()
{
    this->green_->switchOn();
    this->red_->switchOff();

    this->water_sampling_task_->init(this->pe_normal_);
    this->led_blink_task_->setInactive();

    this->state_ = SystemState::Normal;
}

void WaterMonitorController::prealarm_state_handler()
{
    this->led_blink_task_->setActive();
    
    this->water_sampling_task_->init(this->pe_prealarm_);

    this->state_ = SystemState::PreAlarm;

    // TODO: turn on LCD: inform state + display water level
}

void WaterMonitorController::alarm_state_handler()
{
    this->led_blink_task_->setInactive();

    this->red_->switchOn();
    this->green_->switchOff();

    this->state_ = SystemState::Alarm;
}

void WaterMonitorController::handle_current_state()
{
    SystemState new_state = this->get_system_state();

    if (this->state_ == new_state) return;

    switch (new_state)
    {
        case SystemState::Normal:
            this->set_system_state_normal();
        break;
        case SystemState::PreAlarm:
            this->prealarm_state_handler();
        break;
        case SystemState::Alarm:
            this->alarm_state_handler();
        break;
    }
}

bool WaterMonitorController::is_in_alarm_state()
{
    return this->state_ == SystemState::Alarm;
}
