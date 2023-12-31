
#ifndef IMODE_H
#define IMODE_H

#include "igenericbyte.h"
#include <cstdint>
#include <iostream>
#include <optional>
#include <vector>
#include <memory>

class IMode: public IGenericByte
{
private:

public:
    IMode(){}
    virtual ~IMode(){}
    virtual void check_data(std::optional<std::vector<uint8_t>> data) = 0;
    virtual uint8_t get_valid_register() = 0;
};

#endif