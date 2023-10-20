#include <iostream>
#include <stdexcept>
#include "../backlight/command/backlight.h"
#include "../message/message.h"

int main()
{

    std::cout << "Iniciando desafio..." << std::endl;

    std::cout << "***Chamando a classe BackLight***" << std::endl;

    try
    {
        Message *m2 = new Backlight(0x5A,
                                      0xA5,
                                      0x03,
                                      0x80);

        m2->set_register(0x06);                                      
        m2->set_length(0x01);

        m2->execute();

        for (auto bytes : m2->get_bytes())
        {
            std::cout << "[" << static_cast<int>(*bytes) << " ]";
        }
        std::cout << std::endl;
        delete m2;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }

    return 0;
}
