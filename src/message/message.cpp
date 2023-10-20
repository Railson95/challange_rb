#include "../includes/message/message.h"
#include <iostream>

Message::Message(uint8_t frame_header_h,
                 uint8_t frame_header_l,
                 uint8_t byte_count,
                 uint8_t command)
{
    this->frame_header_h = frame_header_h;
    this->frame_header_l = frame_header_l;
    this->byte_count = byte_count;
    this->command = command;
    std::cout << "Chamou o construtor da message" << std::endl;
}

Message::~Message(){}

uint8_t Message::get_frame_header_h(){
    return this->frame_header_h;
}
uint8_t Message::get_frame_header_l(){
    return this->frame_header_l;
}
uint8_t Message::get_byte_count(){
    return this->byte_count;
}
uint8_t Message::get_command(){
    return this->command;
}

std::optional<uint8_t> Message::get_register()
{
    return this->_register;
}

std::optional<uint16_t> Message::get_data()
{
    return this->data;
}

void Message::execute()
{

}

void Message::set_register(std::optional<uint8_t> _register)
{
    this->_register = _register;
}

void Message::set_data(std::optional<uint16_t> data)
{
    this->data = data;
}
void Message::set_length(std::optional<uint8_t> lenght)
{
    this->lenght = lenght;
}

std::vector<std::optional<uint8_t>> Message::get_bytes()
{
    std::vector<std::optional<uint8_t>> bytes;

    // std::cout << "Valor data2: " << static_cast<unsigned int>(this->data) << std::endl;

    bytes.push_back(this->get_frame_header_h());
    bytes.push_back(this->get_frame_header_l());
    bytes.push_back(this->get_byte_count());
    bytes.push_back(this->get_command());
    bytes.push_back(this->_register);
    if (this->lenght.has_value())
        bytes.push_back(this->lenght);
    if (this->data.has_value())
        bytes.push_back(this->data);

    return bytes;
}