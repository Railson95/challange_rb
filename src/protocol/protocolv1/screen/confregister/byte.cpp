
#include "../protocol/protocolv1/screen/confregister/byte.h"


Byte::Byte()
{
    this->min_range_image = 0x00;
    this->max_range_image = 0xFF;
}

Byte::~Byte()
{
    
}


uint8_t Byte::get_min_range_image()
{
    return this->min_range_image;
}


uint8_t Byte::get_max_range_image()
{
    return this->min_range_image;
}
