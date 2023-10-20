
#ifndef MODE_H
#define MODE_H

#include <cstdint>
#include <iostream>

class Mode
{
private:

public:
    Mode();
    ~Mode();
    void check_brightness_lvl(uint16_t data);
    void check_brightness_period(uint16_t data);
    void execute(uint16_t data);
};

#endif