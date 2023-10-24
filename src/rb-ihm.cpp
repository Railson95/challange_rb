#include <iostream>
#include <stdexcept>
#include "../ihm/ihm.h"

int main()
{

    std::cout << "Iniciando desafio..." << std::endl;

    std::cout << "***Chamando a classe BackLight***" << std::endl;
    std::string protocol_type = "protocolv1";
    try
    {
        std::unique_ptr<Ihm> ihm = std::make_unique<Ihm>(protocol_type); 
        ihm->set_backlight_level(0x06, 0x2F);
        ihm->get_backlight_level();
        ihm->set_qrcode_value(0x2040, "Hello RentBrella!");
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }

    return 0;
}
