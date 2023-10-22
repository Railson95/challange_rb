#include "../protocol/protocolv1/protocolv1.h"
#include "../protocol/protocolv1/backlight/message/backlight.h"
#include "../constants/constants.h"

#define BACKLIGHT_LENGHT 0x01

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
    Backlight *backlight = new Backlight(FRAME_HEADER_H, FRAME_HEADER_L, 0X03, READ_REGISTER);
    backlight->set_register(get_operation_mode());
    backlight->set_length(BACKLIGHT_LENGHT);
    backlight->execute();
    /*TODO: implement the correct backlight return, 
    however it was not requested in the exercise*/ 
    return 0;
}

void Protocolv1::set_backlight_level(uint8_t operation_mode, uint8_t level)
{
    Backlight *backlight = new Backlight(FRAME_HEADER_H, FRAME_HEADER_L, 0x03, WRITE_REGISTER);
    backlight->set_register(operation_mode);
    backlight->set_data(level);
    this->set_operation_mode(operation_mode);
    backlight->execute();
}


