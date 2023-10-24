
#ifndef IMODE_H
#define IMODE_H

#include <cstdint>
#include <iostream>
#include <optional>
#include <vector>
#include <memory>

class IMode
{
private:

public:
    IMode(){}
    ~IMode(){}
    virtual void check_brightness_lvl(std::optional<uint8_t> data) = 0;
    virtual void check_data(std::optional<std::vector<uint8_t>> data) = 0;
};

#endif