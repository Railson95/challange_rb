#include <iostream>
#include <stdexcept>
#include "backlight.h"
int main()
{
    
    
    std::cout << "Iniciando desafio..." << std::endl;

    // IMessage *m = new Message(0x00, 0x00, 0x00, 0x00);

    // m->get_bytes();


    std::cout << "***Chamando a classe BackLight***" << std::endl;

    
    try
    {
        Backlight *m2 = new Backlight(0x5A, 0xA5, 0x03, 0x80, 0x06, 0x3F);
        // m2->check_mode(0x06, 0xFF);

        for (auto bytes : m2->get_bytes()) {
            std::cout << "[" <<  static_cast<unsigned int>(bytes) << " ]";
        }
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
    

    

    
    

    return 0;
}
