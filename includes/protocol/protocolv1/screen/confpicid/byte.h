#ifndef BYTE_H
#define BYTE_H

#include "../protocol/protocolv1/screen/confpicid/ibyte.h"


class Byte: public IByte
{
private:
    uint8_t min_pic_id;
    uint8_t max_pic_id;
public:
    Byte(/* args */);
    ~Byte();
    uint8_t get_min_pic_id();
    uint8_t get_max_pic_id();
    void check_data(std::optional<std::vector<uint8_t>> data);
    void check_pic_id(std::optional<uint8_t> data);
};




#endif 