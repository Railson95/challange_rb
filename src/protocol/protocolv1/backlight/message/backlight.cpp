#include "../protocol/protocolv1/backlight/message/backlight.h"
#include "../protocol/protocolv1/backlight/mode/factory.h"
#include <iostream>


Backlight::Backlight(uint8_t frame_header_h,
                     uint8_t frame_header_l,
                     uint8_t byte_count,
                     uint8_t command) : Message(frame_header_h,
                                                frame_header_l,
                                                byte_count,
                                                command)

{
    std::cout << "Chamou construtor do backlight" << std::endl;
}

Backlight::~Backlight() {}

void Backlight::execute()
{
    BrightnessModeFactory *factory = new BrightnessModeFactory();
    factory->create_brightness_factory(get_register())->check_data(get_data());
    std::cout << "Escreve bytes na UART: ";
    for (auto bytes : this->get_bytes())
    {
        std::cout << "[" << static_cast<int>(*bytes) << " ]";
    }
    std::cout << std::endl;

    delete factory;

}