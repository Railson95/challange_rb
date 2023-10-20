#ifndef MESSAGE_H
#define MESSAGE_H

#include <optional>
#include "imessage.h"

class Message: public IMessage
{
private:
    uint8_t frame_header_h;
    uint8_t frame_header_l;
    uint8_t byte_count;
    uint8_t command;
    std::optional<uint8_t> _register;
    std::optional<uint16_t> data;
    std::optional<uint8_t> lenght;
public:
    Message(uint8_t frame_header_h,
            uint8_t frame_header_l,
            uint8_t byte_count,
            uint8_t command);
    ~Message();
    std::vector<std::optional<uint8_t>> get_bytes();
    uint8_t get_frame_header_h();
    uint8_t get_frame_header_l();
    uint8_t get_byte_count();
    uint8_t get_command();
    std::optional<uint8_t> get_register();
    std::optional<uint16_t> get_data();
    void set_register(std::optional<uint8_t> _register);
    void set_data(std::optional<uint16_t> data);
    void set_length(std::optional<uint8_t> lenght);
    void execute();
};

#endif
