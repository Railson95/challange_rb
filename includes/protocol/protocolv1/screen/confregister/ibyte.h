#ifndef IBYTE_H
#define IBYTE_H
#include <cstdint>
#include <vector>
#include <optional>

class IByte
{
private:
   
public:
    IByte(/* args */){}
    ~IByte(){}
    virtual uint8_t get_valid_register() = 0;
    virtual uint8_t get_min_pic_id() = 0;
    virtual uint8_t get_max_pic_id() = 0;
    virtual void check_data(std::optional<std::vector<uint8_t>> data) = 0;
};




#endif 