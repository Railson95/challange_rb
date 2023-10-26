#ifndef IBYTE_H
#define IBYTE_H
#include <cstdint>


class IByte
{
private:
   
public:
    IByte(/* args */){}
    ~IByte(){}
    virtual uint8_t get_byte() = 0;
    virtual uint8_t get_min_range_image() = 0;
    virtual uint8_t get_max_range_image() = 0;
};




#endif 