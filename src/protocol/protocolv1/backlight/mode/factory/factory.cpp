#include "../protocol/protocolv1/backlight/mode/factory/factory.h"
#include "../protocol/protocolv1/backlight/mode/normal_mode.h"
#include "../protocol/protocolv1/backlight/mode/low_mode.h"
#include "../protocol/protocolv1/backlight/mode/period_mode.h"
#include "../protocol/protocolv1/backlight/mode/imode.h"
#define NORMAL_MODE 0x06 // Brightness level at normal mode.
#define LOW_MODE 0x07    // Brightness level at low-brightness mode
#define PERIOD_MODE 0x08 // LCM will enter low-brightness mode


BrightnessModeFactory::BrightnessModeFactory()
{

}

BrightnessModeFactory::~BrightnessModeFactory()
{
    
}

std::unique_ptr<IMode> BrightnessModeFactory::create_brightness_factory(std::optional<uint8_t> _register)
{
    std::unique_ptr<IMode> normal_mode = std::make_unique<NormalMode>();
    std::unique_ptr<IMode> low_mode = std::make_unique<LowMode>();
    std::unique_ptr<IMode> period_mode = std::make_unique<PeriodMode>();

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