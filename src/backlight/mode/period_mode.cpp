
#include "../backlight/mode/period_mode.h"


PeriodMode::PeriodMode():Mode()
{

}

PeriodMode::~PeriodMode()
{

}


void PeriodMode::execute(std::optional<uint16_t> data)
{
    check_brightness_period(data);
}
