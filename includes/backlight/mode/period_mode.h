
#ifndef PERIOD_MODE_H
#define PERIOD_MODE_H

#include "mode.h"


class PeriodMode: public Mode
{
private:

public:
    PeriodMode();
    ~PeriodMode();
    void execute(uint16_t data);
};

#endif

