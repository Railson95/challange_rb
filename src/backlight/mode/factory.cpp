#include "../backlight/mode/factory.h"
#include "../backlight/mode/normal_mode.h"
#include "../backlight/mode/low_mode.h"
#include "../backlight/mode/period_mode.h"
#define NORMAL_MODE 0x06 // Brightness level at normal mode.
#define LOW_MODE 0x07    // Brightness level at low-brightness mode
#define PERIOD_MODE 0x08 // LCM will enter low-brightness mode


BrightnessModeFactory::BrightnessModeFactory()
{

}

BrightnessModeFactory::~BrightnessModeFactory()
{
    
}

Mode *BrightnessModeFactory::create_brightness_factory(std::optional<uint8_t> _register)
{
    Mode *normal_mode = new NormalMode();
    Mode *low_mode = new LowMode();
    Mode *period_mode = new PeriodMode();

    int result = static_cast<int>(*_register);

    switch (result)
    {
    case NORMAL_MODE:
        return normal_mode;
        break;

    case LOW_MODE:
        return low_mode;
        break;

    case PERIOD_MODE:
        return period_mode;
        break;
    
    default:
        throw std::out_of_range("Invalid register!");
        break;
    }

}