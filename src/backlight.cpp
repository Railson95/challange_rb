#include "backlight.h"
#include <iostream>
#define BRIGHTNESS_MIN 0x00
#define BRIGHTNESS_MAX 0x3F
#define BRIGHTNESS_PERIOD_MIN 0x00
#define BRIGHTNESS_PERIOD_MAX 0xFF
#define REGISTER_MIN 0x06
#define REGISTER_MAX 0x08
#define NORMAL_MODE 0x06 // Brightness level at normal mode.
#define LOW_MODE 0x07    // Brightness level at low-brightness mode
#define PERIOD_MODE 0x08 // LCM will enter low-brightness mode

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
    check_register(_register);
    check_mode(_register, data);
    std::cout << "Valor data1: " << static_cast<unsigned int>(data) << std::endl;
    std::cout << "Chamou construtor do backlight" << std::endl;
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

void Backlight::check_mode(uint8_t _register, uint16_t data)
{
    if (_register == NORMAL_MODE || _register == LOW_MODE)
    {
        check_brightness_lvl(data);
    }
    if (_register == PERIOD_MODE)
    {
        check_brightness_period(data);
    }
}

void Backlight::check_brightness_lvl(uint16_t data)
{
    if (!(data >= BRIGHTNESS_MIN && data <= BRIGHTNESS_MAX))
    {
        throw std::out_of_range("Invalid brightness level! ");
    }
}

void Backlight::check_brightness_period(uint16_t data)
{
    if (!(data >= BRIGHTNESS_PERIOD_MIN && data <= BRIGHTNESS_PERIOD_MAX))
    {
        throw std::out_of_range("Invalid brightness period!");
    }
}

void Backlight::check_register(uint8_t _register)
{
    if (!(_register >= REGISTER_MIN && _register <= REGISTER_MAX))
    {
        throw std::out_of_range("Invalid register!");
    }
}