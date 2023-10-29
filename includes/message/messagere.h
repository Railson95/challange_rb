#ifndef MESSAGERE_H
#define MESSAGERE_H

#include "message.h"

class MessageRE : public Message
{
private:
    
public:
    MessageRE(uint8_t frame_header_h,
              uint8_t frame_header_l,
              uint8_t command);
    ~MessageRE();
    uint16_t get_memory_max();
    uint16_t get_memory_address();
    uint8_t calc_byte_count();
};


#endif