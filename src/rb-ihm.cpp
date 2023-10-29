#include <iostream>
#include <stdexcept>
#include "../ihm/ihm.h"

int main()
{
    std::string protocol_type = "protocolv1";
    char msg[] = "Hello RentBrella!";
    try
    {
        std::unique_ptr<Ihm> ihm = std::make_unique<Ihm>(protocol_type); 
        ihm->set_backlight_level(0x06, 0x3F);
        ihm->get_backlight_level();
        ihm->set_qrcode_value(0x2040, msg);
        ihm->set_screen(0x3F);
        ihm->get_button_value(0x2040);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }

    return 0;
}
