#include "../protocolv1/screen/confpicid/lowbyte.h"


LowByteRegister::LowByteRegister()
{
    this->low_byte = 0x0E;
}

LowByteRegister::~LowByteRegister()
{
    
}


uint8_t LowByteRegister::get_valid_register()
{
    return this->low_byte;
}
