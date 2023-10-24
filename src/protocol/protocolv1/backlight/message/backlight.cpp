#include "../protocol/protocolv1/backlight/message/backlight.h"
#include "../protocol/protocolv1/backlight/mode/factory/factory.h"
#include "../uart/uart.h"
#include "../utils/utils.h"
#include <iostream>


Backlight::Backlight(uint8_t frame_header_h,
                     uint8_t frame_header_l,
                     uint8_t command) : Message(frame_header_h,
                                                frame_header_l,
                                                command)

{
    std::cout << "Chamou construtor do backlight" << std::endl;
}

Backlight::~Backlight() {}

void Backlight::execute()
{
    std::unique_ptr<BrightnessModeFactory> factory = std::make_unique<BrightnessModeFactory>();
    std::unique_ptr<IMode> mode = factory->create_brightness_factory(get_register());

    std::optional<std::vector<uint8_t>> data;

    data = this->get_data();

    this->set_byte_count(this->calc_byte_count());

    if(data.has_value()){
        
        mode->check_data(get_data());
        if(is_memory_overflow())
        {
            throw std::overflow_error("Memory Overflow! ");
        }
    }

    Uart *u = new Uart();
    Utils *utils = new Utils();
    size_t bytes_length = this->get_bytes().size();
    unsigned char * bytes = utils->to_char_pointer(this->get_bytes());
    u->send(bytes, bytes_length);
    std::cout << std::endl;

}

uint8_t Backlight::calc_byte_count()
{
    uint8_t size_lenght = (this->get_lenght().has_value())? 1:0;
    uint8_t size_data = (this->get_data().has_value())? this->get_data().value().size():0; 
    size_t cmd_reg = 2; // lenght cmd plus register

    if(this->get_lenght().has_value() && this->get_data().has_value()){
        return size_lenght + size_data + cmd_reg;
    }

    if(this->get_lenght().has_value()){
        return size_lenght + cmd_reg;
    }

    if(this->get_data().has_value()){
        return this->get_data().value().size() + cmd_reg;
    }
}

uint16_t Backlight::get_memory_max()
{
    return 0xFF;
}

uint16_t Backlight::get_memory_address()
{
    std::optional<uint8_t> _register = get_register();
    if(!_register.has_value()){
        std::cout << "Invalid Register! " << std::endl;
        return true;
    }
    return _register.value();
}

