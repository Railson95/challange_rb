
#include "../protocol/protocolv1/backlight/mode/period_mode.h"
#define BRIGHTNESS_PERIOD_MIN 0x00
#define BRIGHTNESS_PERIOD_MAX 0xFF
#define PERIOD_MODE 0x08 // LCM will enter low-brightness mode

PeriodMode::PeriodMode():Mode()
{
    this->period_mode = PERIOD_MODE;
}

PeriodMode::~PeriodMode()
{

}


void PeriodMode::check_data(std::optional<std::vector<uint8_t>> data)
{
    
}

void PeriodMode::check_period_mode(std::optional<uint8_t> data)
{
    if (!(data >= BRIGHTNESS_PERIOD_MIN && data <= BRIGHTNESS_PERIOD_MAX))
    {
        throw std::out_of_range("Invalid brightness level! ");
    }
}


uint8_t PeriodMode::get_valid_register()
{
    return this->period_mode;
}
