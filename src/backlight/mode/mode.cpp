
#include "../backlight/mode/mode.h"
#define BRIGHTNESS_MIN 0x00
#define BRIGHTNESS_MAX 0x3F
#define BRIGHTNESS_PERIOD_MIN 0x00
#define BRIGHTNESS_PERIOD_MAX 0xFF


Mode::Mode()
{
    
}

Mode::~Mode()
{
    
}

void Mode::execute(std::optional<uint16_t> data){
    if(!data.has_value()) {
        std::cout << "Invalid data! " << std::endl;
        return;
    }    
    check_brightness_lvl(data);
}

void Mode::check_brightness_lvl(std::optional<uint16_t> data)
{
    if (!(data >= BRIGHTNESS_MIN && data <= BRIGHTNESS_MAX))
    {
        throw std::out_of_range("Invalid brightness level! ");
    }
}

void Mode::check_brightness_period(std::optional<uint16_t> data)
{
    if (!(data >= BRIGHTNESS_PERIOD_MIN && data <= BRIGHTNESS_PERIOD_MAX))
    {
        throw std::out_of_range("Invalid brightness period!");
    }
}

