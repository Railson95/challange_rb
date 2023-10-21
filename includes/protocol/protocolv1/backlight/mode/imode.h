
#ifndef IMODE_H
#define IMODE_H

#include <cstdint>
#include <iostream>
#include <optional>

class IMode
{
private:

public:
    IMode(){}
    ~IMode(){}
    virtual void check_brightness_lvl(std::optional<uint16_t> data) = 0;
    virtual void check_brightness_period(std::optional<uint16_t> data) = 0;
    virtual void check_data(std::optional<uint16_t> data) = 0;
};

#endif