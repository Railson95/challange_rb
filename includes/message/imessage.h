#ifndef IMESSAGE_H
#define IMESSAGE_H

#include "../protocol/protocolv1/igenericbyte.h"
#include "icommnad.h"
#include <memory>
#include <vector>
#include <cstdint>

class IMessage: public ICommand
{
public:
    IMessage(){}
    virtual ~IMessage(){}
    virtual std::vector<uint8_t> get_bytes() = 0;
    virtual uint8_t get_frame_header_h() = 0;
    virtual uint8_t get_frame_header_l() = 0;
    virtual uint8_t get_command() = 0;
    virtual uint16_t get_memory_max() = 0;
    virtual uint16_t get_memory_address() = 0;
    virtual uint8_t get_byte_count() = 0;
    virtual void set_byte_count(uint8_t byte_count) = 0;
};

#endif