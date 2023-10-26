#include "../protocolv1/screen/confregister/lowbyte.h"


LowByteRegister::LowByteRegister()
{
    this->low_byte = 0x0E;
}

LowByteRegister::~LowByteRegister()
{
    
}


uint8_t LowByteRegister::get_byte()
{
    return this->low_byte;
}
