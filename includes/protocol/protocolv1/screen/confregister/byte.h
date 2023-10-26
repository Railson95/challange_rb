#ifndef BYTE_H
#define BYTE_H

#include "../protocol/protocolv1/screen/confregister/ibyte.h"


class Byte: public IByte
{
private:
    uint8_t min_range_image;
    uint8_t max_range_image;
public:
    Byte(/* args */);
    ~Byte();
    uint8_t get_min_range_image();
    uint8_t get_max_range_image();
};




#endif 