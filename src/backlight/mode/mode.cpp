
#include "../backlight/mode/mode.h"
#include "../backlight/mode/normal_mode.h"
#include "../backlight/mode/low_mode.h"
#include "../backlight/mode/period_mode.h"
#define BRIGHTNESS_MIN 0x00
#define BRIGHTNESS_MAX 0x3F
#define BRIGHTNESS_PERIOD_MIN 0x00
#define BRIGHTNESS_PERIOD_MAX 0xFF
#define NORMAL_MODE 0x06 // Brightness level at normal mode.
#define LOW_MODE 0x07    // Brightness level at low-brightness mode
#define PERIOD_MODE 0x08 // LCM will enter low-brightness mode

Mode::Mode()
{
    
}

Mode::~Mode()
{
    
}

void Mode::check_mode(uint8_t _register, uint16_t data)
{ 
    Mode *normal_mode = new NormalMode();
    Mode *low_mode = new LowMode();
    Mode *period_mode = new PeriodMode();
    if (_register == NORMAL_MODE )
    {
        normal_mode->check_brightness_lvl(data);
    }
    if(_register == LOW_MODE){
        low_mode->check_brightness_lvl(data);
    }
    if (_register == PERIOD_MODE)
    {
        period_mode->check_brightness_period(data);
    }
    delete normal_mode;
    delete low_mode;
    delete period_mode;
}


void Mode::check_brightness_lvl(uint16_t data)
{
    if (!(data >= BRIGHTNESS_MIN && data <= BRIGHTNESS_MAX))
    {
        throw std::out_of_range("Invalid brightness level! ");
    }
}

void Mode::check_brightness_period(uint16_t data)
{
    if (!(data >= BRIGHTNESS_PERIOD_MIN && data <= BRIGHTNESS_PERIOD_MAX))
    {
        throw std::out_of_range("Invalid brightness period!");
    }
}

