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
    IMode *mode = factory->create_brightness_factory(get_register());

    std::optional<std::vector<uint8_t>> data;

    data = this->get_data();

    if(data.has_value()){
        mode->check_data(get_data());
        if(is_memory_overflow())
        {
            throw std::overflow_error("Memory Overflow! ");
        }
    }

    std::cout << "Escreve bytes na UART: ";
    for (auto bytes : this->get_bytes())
    {
        std::cout << "[" << static_cast<int>(*bytes) << " ]";
    }
    std::cout << std::endl;

    delete factory;

}


uint8_t Backlight::get_memory_max()
{
    return 0xFF;
}


uint8_t Backlight::get_memory_addrs()
{
    std::optional<uint8_t> _register = get_register();
    if(!_register.has_value()){
        std::cout << "Invalid Register! " << std::endl;
        return true;
    }
    return _register.value();
}

