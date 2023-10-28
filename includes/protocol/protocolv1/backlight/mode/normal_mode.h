
#ifndef NORMAL_MODE_H
#define NORMAL_MODE_H

#include "mode.h"


class NormalMode: public Mode
{
private:
    uint8_t normal_mode;
public:
    NormalMode();
    NormalMode(const NormalMode &other);
    ~NormalMode();
    uint8_t get_valid_register();
};

#endif

