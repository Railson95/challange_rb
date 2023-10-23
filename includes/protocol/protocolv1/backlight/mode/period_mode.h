
#ifndef PERIOD_MODE_H
#define PERIOD_MODE_H

#include "mode.h"


class PeriodMode: public Mode
{
private:

public:
    PeriodMode();
    ~PeriodMode();
    void check_data(std::optional<std::vector<uint8_t>> data);
};

#endif

