#ifndef IBYTE_H
#define IBYTE_H
#include "igenericbyte.h"
#include <cstdint>
#include <vector>
#include <optional>

class IByte: public IGenericByte
{
private:
   
public:
    IByte(/* args */){}
    ~IByte(){}
    virtual uint8_t get_min_pic_id() = 0;
    virtual uint8_t get_max_pic_id() = 0;
};




#endif 