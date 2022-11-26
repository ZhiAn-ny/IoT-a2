#include "WaterMonitor.h"

using namespace bridge_control::water_monitor;

WaterMonitorController::WaterMonitorController() {}
WaterMonitorController::~WaterMonitorController() {}

void WaterMonitorController::init_lights(int green, int red)
{
    this->green_ = new Led(green);
    this->red_ = new Led(red);
}

void WaterMonitorController::init(int period)
{
    Task::init(period);
    this->init_lights(LED_PIN_B, LED_PIN_C);
    
    // TODO: Init Sonar
}


void WaterMonitorController::tick()
{

}
