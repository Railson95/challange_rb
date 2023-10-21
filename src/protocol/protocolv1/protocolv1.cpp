#include "../protocol/protocolv1/protocolv1.h"
#include "../protocol/protocolv1/backlight/message/backlight.h"


Protocolv1::Protocolv1()
{

}

Protocolv1::~Protocolv1()
{
    
}

uint8_t Protocolv1::get_backlight_level()
{
    if(get_operation_mode() == 0)
    {
        std::cout << "Operating mode not yet defined" << std::endl;
        return 0;
    }
    Backlight *backlight = new Backlight(0x5A, 0xA5, 0X03, 0X81);
    backlight->set_register(get_operation_mode());
    backlight->set_length(0x01);
    backlight->execute();
    return 0;
}

void Protocolv1::set_backlight_level(uint8_t operation_mode, uint8_t level)
{
    Backlight *backlight = new Backlight(0x5A, 0xA5, 0x03, 0x80);
    backlight->set_register(operation_mode);
    backlight->set_data(level);
    this->set_operation_mode(operation_mode);
    backlight->execute();
}


