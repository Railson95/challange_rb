
#include "../protocol/protocolv1/backlight/mode/period_mode.h"


PeriodMode::PeriodMode():Mode()
{

}

PeriodMode::~PeriodMode()
{

}


void PeriodMode::check_data(std::optional<uint16_t> data)
{
    const std::type_info& tipo = typeid(this);
    std::cout << "Execute Class { " << tipo.name() << " }" << std::endl;
    if(!data.has_value()) {
        std::cout << "Invalid data! " << std::endl;
        return;
    }
    check_brightness_period(data);
}
