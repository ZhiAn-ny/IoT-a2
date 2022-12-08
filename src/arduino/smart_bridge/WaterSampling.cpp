#include "WaterSampling.h"

using namespace bridge_scheduling::tasks;
using namespace pins;

WaterSamplingTask::WaterSamplingTask(float* water_level)
{
    this->sonar_ = new Sonar(sonar::trigger, sonar::echo);
    this->water_surface_dist_ = water_level;
}

void WaterSamplingTask::init(int period)
{
    Task::init(period);
    *this->water_surface_dist_ = 0.0;
}

void WaterSamplingTask::tick()
{
    if (!this->isActive()) return;
    
    *this->water_surface_dist_ = this->sonar_->getDistance();
}
