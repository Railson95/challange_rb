#include "../backlight/command/backlight.h"
#include "../backlight/mode/factory.h"

#include <iostream>
#define REGISTER_MIN 0x06
#define REGISTER_MAX 0x08

Backlight::Backlight(uint8_t frame_header_h,
                     uint8_t frame_header_l,
                     uint8_t byte_count,
                     uint8_t command,
                     uint8_t _register,
                     uint16_t data) : Message(frame_header_h,
                                              frame_header_l,
                                              byte_count,
                                              command,
                                              _register,
                                              data)
{
    this->_register = _register;
    this->data = data;
    BrightnessModeFactory *factory = new BrightnessModeFactory();
    factory->create_brightness_factory(_register)->execute(data);
    std::cout << "Valor data1: " << static_cast<unsigned int>(data) << std::endl;
    std::cout << "Chamou construtor do backlight" << std::endl;
    delete factory;
}

Backlight::~Backlight() {}

std::vector<uint8_t> Backlight::get_bytes()
{
    std::vector<uint8_t> bytes;

    std::cout << "Valor data2: " << static_cast<unsigned int>(this->data) << std::endl;

    bytes.push_back(this->get_frame_header_h());
    bytes.push_back(this->get_frame_header_l());
    bytes.push_back(this->get_byte_count());
    bytes.push_back(this->get_command());
    bytes.push_back(this->_register);
    bytes.push_back(this->data);
    return bytes;
}

void Backlight::execute()
{
}