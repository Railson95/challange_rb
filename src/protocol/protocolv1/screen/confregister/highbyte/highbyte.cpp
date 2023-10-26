#include "../highbyte/highbyte.h"


HighByteRegister::HighByteRegister()
{
    this->high_byte = 0x0D;
}


uint8_t HighByteRegister::get_byte()
{
    return this->high_byte;
}
