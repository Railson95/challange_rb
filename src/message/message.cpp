#include "../includes/message/message.h"
#include <iostream>

Message::Message(uint8_t frame_header_h,
                 uint8_t frame_header_l,
                 uint8_t byte_count,
                 uint8_t command,
                 std::optional<uint8_t> _register,
                 std::optional<uint16_t> data)
{
    this->frame_header_h = frame_header_h;
    this->frame_header_l = frame_header_l;
    this->byte_count = byte_count;
    this->command = command;
    this->_register = _register;
    this->data = data;
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

void Message::execute()
{
    
}