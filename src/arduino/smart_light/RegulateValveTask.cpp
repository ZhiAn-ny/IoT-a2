#include "RegulateValveTask.h"

#define DEBUG

using namespace bridge_scheduling::tasks;
using namespace bridge_control::water_level;

RegulateValveTask::RegulateValveTask(Motor* valve, float* water_level) {
    this->valve_ = valve;
    this->water_distance_ = water_level;
}

int RegulateValveTask::get_degrees()
{
    if (*this->water_distance_ >= water_level_2) {
        return 0;
    }
    if (*this->water_distance_ <= water_level_max) {
        return 180;
    }

    return (*this->water_distance_ - water_level_2) * 180 
            / (water_level_max - water_level_2);
}

void RegulateValveTask::init(int period)
{
    Task::init(period);
}

void RegulateValveTask::tick()
{
    int deg = this->get_degrees();
#ifdef DEBUG
    Serial.print("Degrees: "); Serial.println(deg);

#endif // !DEBUG


    //this->valve_->open_valve(deg);
}
