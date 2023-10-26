#include "../lowbyte/lowbyte.h"


LowByteRegister::LowByteRegister()
{
    this->low_byte = 0x0E;
}


uint8_t LowByteRegister::get_byte()
{
    return this->low_byte;
}
