#include "../protocol/protocolv1/backlight/mode/factory/factory.h"
#include "../protocol/protocolv1/backlight/mode/normal_mode.h"
#include "../protocol/protocolv1/backlight/mode/low_mode.h"
#include "../protocol/protocolv1/backlight/mode/period_mode.h"
#include "../protocol/protocolv1/backlight/mode/imode.h"

BrightnessModeFactory::BrightnessModeFactory()
{

}

BrightnessModeFactory::~BrightnessModeFactory()
{
    
}

std::unique_ptr<IMode> BrightnessModeFactory::create_brightness_factory(std::optional<uint8_t> _register)
{
    if (!_register.has_value()) {
        throw std::invalid_argument("Invalid register: No value provided.");
    }

    std::unique_ptr<IMode> normal_mode = std::make_unique<NormalMode>();
    std::unique_ptr<IMode> low_mode = std::make_unique<LowMode>();
    std::unique_ptr<IMode> period_mode = std::make_unique<PeriodMode>();

    int result = static_cast<int>(*_register);
    int result_normal_mode = normal_mode->get_valid_register();
    int result_low_mode = low_mode->get_valid_register();
    int result_period_mode = period_mode->get_valid_register();


    if(!(result >= result_normal_mode && result <= result_period_mode))
    {
         throw std::out_of_range("Invalid register!");
    }

    if(result == result_normal_mode)
    {
        return normal_mode;
    }

    if(result == result_low_mode)
    {
        return low_mode;
    }

    if(result == result_period_mode)
    {
        return period_mode;
    }
}