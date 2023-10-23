#ifndef MESSAGE_H
#define MESSAGE_H

#include <optional>
#include <string>
#include <iostream>
#include "imessage.h"
class Message: public IMessage
{
private:
    uint8_t frame_header_h;
    uint8_t frame_header_l;
    uint8_t command;
    uint8_t byte_count;
    std::optional<uint8_t> _register;
    std::optional<std::vector<uint8_t>> data;
    std::optional<uint8_t> lenght;
    std::optional<std::vector<uint16_t>> vp_address;
public:
    Message(uint8_t frame_header_h,
            uint8_t frame_header_l,
            uint8_t command);
    ~Message();
    std::vector<std::optional<uint8_t>> get_bytes();
    std::vector<uint8_t> split_vp_address();
    uint8_t get_frame_header_h();
    uint8_t get_frame_header_l();
    uint8_t get_byte_count();
    uint8_t get_command();
    std::optional<std::vector<uint16_t>> get_vp_address();
    std::optional<uint8_t> get_lenght();
    std::optional<uint8_t> get_register();
    std::optional<std::vector<uint8_t>> get_data();
    bool is_memory_overflow();
    void set_register(std::optional<uint8_t> _register);
    void set_data(std::optional<std::vector<uint8_t>>  data);
    void set_data(char *data);
    void set_length(std::optional<uint8_t> lenght);
    void set_byte_count(uint8_t byte_count);
    void set_vp_address(std::optional<std::vector<uint16_t>> vp_address); 
    void execute();
};

#endif
