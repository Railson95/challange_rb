#ifndef BUTTON_H
#define BUTTON_H

#include "message.h"

class MessageVP : public Message
{
private:
    
public:
    MessageVP(uint8_t frame_header_h,
              uint8_t frame_header_l,
              uint8_t command);
    ~MessageVP();
    uint16_t get_memory_max();
    uint16_t get_memory_address();
    uint8_t calc_byte_count();
};


#endif