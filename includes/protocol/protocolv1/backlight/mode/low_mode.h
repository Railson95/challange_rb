
#ifndef LOW_MODE_H
#define LOW_MODE_H

#include "mode.h"


class LowMode: public Mode
{
private:
    uint8_t low_mode;
public:
    LowMode();
    virtual ~LowMode();
    uint8_t get_valid_register();
};


#endif