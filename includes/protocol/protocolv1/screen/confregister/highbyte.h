#ifndef HIGH_BYTE_H
#define HIGH_BYTE_H
#include <cstdint>
#include "byte.h"

class HighByteRegister: public Byte
{
private:
    uint8_t high_byte;
public:
    HighByteRegister(/* args */);
    ~HighByteRegister();
    uint8_t get_valid_register();
};




#endif 