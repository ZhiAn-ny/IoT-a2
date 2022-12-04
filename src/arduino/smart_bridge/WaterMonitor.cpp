#include "WaterMonitor.h"

using namespace bridge_control::water_monitor;
using namespace bridge_control::water_level;
using namespace bridge_control::sampling_periods;
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

void WaterMonitorController::init(Scheduler* sched)
{
    this->init_lights(led::green, led::red);
    this->set_tasks(sched);
    this->display_.init();

#ifdef USE_BRIDGE_VALVE
    this->valve_controller_.init(sched, &this->water_surface_dist_);
#endif

    this->loop();
}

SystemState WaterMonitorController::get_system_state()
{
    if (this->water_surface_dist_ > water_level_1) {
        return SystemState::Normal;

    } else if (this->water_surface_dist_ > water_level_2) {        
        return SystemState::PreAlarm;

    } else if (this->water_surface_dist_ > water_level_max) {
        return SystemState::Alarm;
    }
    //Serial.print("State undefined, distance is ");
    //Serial.println(this->water_surface_dist_);
    return SystemState::Undefined;
}

void WaterMonitorController::set_system_state_normal()
{
    Serial.println("NORMAL STATE");
    this->green_->switchOn();
    this->red_->switchOff();
    this->led_blink_task_->setInactive();

    this->water_sampling_task_->init(pe_normal);
#ifdef USE_BRIDGE_VALVE
    this->valve_controller_.deactivate();
#endif

    this->state_ = SystemState::Normal;
}

void WaterMonitorController::set_system_state_prealarm()
{
    Serial.println("PRE-ALARM STATE");
    this->display_.print_pre_alarm();

    this->green_->switchOn();
    this->led_blink_task_->setActive();
    
    this->water_sampling_task_->init(pe_prealarm);
#ifdef USE_BRIDGE_VALVE
    this->valve_controller_.deactivate();
#endif

    this->state_ = SystemState::PreAlarm;
}

void WaterMonitorController::set_system_state_alarm()
{
    Serial.println("ALARM STATE");
    this->led_blink_task_->setInactive();

    this->red_->switchOn();
    this->green_->switchOff();

    this->water_sampling_task_->init(pe_alarm);
#ifdef USE_BRIDGE_VALVE
    this->valve_controller_.activate();
#endif

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

#ifdef USE_BRIDGE_VALVE
            int deg = this->valve_controller_.get_opening_degrees();
            this->display_.print_water_and_degrees(this->water_surface_dist_, deg);
#endif
        break;
        case SystemState::Undefined:
        break;
    }
}

bool WaterMonitorController::is_in_alarm_state()
{
    return this->state_ == SystemState::Alarm;
}
