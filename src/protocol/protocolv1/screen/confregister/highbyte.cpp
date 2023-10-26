#include "../protocol/protocolv1/screen/confregister/highbyte.h"


HighByteRegister::HighByteRegister()
{
    this->high_byte = 0x0D;
}


HighByteRegister::~HighByteRegister()
{
    
}

uint8_t HighByteRegister::get_byte()
{
    return this->high_byte;
}
