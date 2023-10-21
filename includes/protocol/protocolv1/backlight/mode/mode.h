
#ifndef MODE_H
#define MODE_H

#include "../protocol/protocolv1/backlight/mode/imode.h"

class Mode: public IMode
{
private:

public:
    Mode();
    ~Mode();
    void check_brightness_lvl(std::optional<uint16_t> data);
    void check_brightness_period(std::optional<uint16_t> data);
    void check_data(std::optional<uint16_t> data);
};

#endif