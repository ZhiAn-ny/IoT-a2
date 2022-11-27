#include "WaterSampling.h"

using namespace bridge_scheduling::tasks;

WaterSamplingTask::WaterSamplingTask(float* water_level)
{
    this->sonar_ = new Sonar(S_TRIG_PIN, S_ECHO_PIN);
    this->water_level_ = water_level;
}

void WaterSamplingTask::init(int period)
{
    Task::init(period);
    *this->water_level_ = 0.0;
}

void WaterSamplingTask::tick()
{
    if (!this->isActive()) return;
    
    *this->water_level_ = this->sonar_->getDistance();
}
