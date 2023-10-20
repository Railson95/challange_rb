
#ifndef MODE_H
#define MODE_H

#include <cstdint>
#include <iostream>
#include <optional>

class Mode
{
private:

public:
    Mode();
    ~Mode();
    void check_brightness_lvl(std::optional<uint16_t> data);
    void check_brightness_period(std::optional<uint16_t> data);
    void execute(std::optional<uint16_t> data);
};

#endif