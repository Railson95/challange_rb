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
        Ihm *ihm = new Ihm(protocol_type);
        ihm->set_backlight_level(0x08, 0x3F);
        ihm->get_backlight_level();
        delete ihm;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }

    return 0;
}
