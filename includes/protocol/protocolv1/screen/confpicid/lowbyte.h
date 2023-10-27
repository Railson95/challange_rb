#ifndef LOW_BYTE_H
#define LOW_BYTE_H
#include "byte.h"

class LowByteRegister: public Byte
{
private:
    uint8_t low_byte;
public:
    LowByteRegister(/* args */);
    ~LowByteRegister();
    uint8_t get_valid_register();
};

#endif