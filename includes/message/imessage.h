#ifndef IMESSAGE_H
#define IMESSAGE_H

#include <vector>
#include <cstdint>

class IMessage
{
public:
    IMessage(){}
    virtual ~IMessage(){}
    virtual std::vector<std::optional<uint8_t>> get_bytes() = 0;
    virtual uint8_t get_frame_header_h() = 0;
    virtual uint8_t get_frame_header_l() = 0;
    virtual uint8_t get_byte_count()= 0;
    virtual uint8_t get_command() = 0;
    virtual void execute() = 0;
};

#endif