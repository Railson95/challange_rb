
#ifndef PERIOD_MODE_H
#define PERIOD_MODE_H

#include "mode.h"


class PeriodMode: public Mode
{
private:
    uint8_t period_mode;
public:
    PeriodMode();
    ~PeriodMode();
    void check_data(std::optional<std::vector<uint8_t>> data);
    void check_period_mode(std::optional<uint8_t> data);
    uint8_t get_valid_register();
};

#endif

