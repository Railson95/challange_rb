#ifndef IGENERIC_BYTE_H
#define IGENERIC_BYTE_H
#include <cstdint>
#include <vector>
#include <optional>

class IGenericByte
{
private:
   
public:
    IGenericByte(/* args */){}
    virtual ~IGenericByte(){}
    virtual uint8_t get_valid_register() = 0;
    virtual void check_data(std::optional<std::vector<uint8_t>> data) = 0;
};

#endif 