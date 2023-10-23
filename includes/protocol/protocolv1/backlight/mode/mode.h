
#ifndef MODE_H
#define MODE_H

#include "../protocol/protocolv1/backlight/mode/imode.h"

class Mode: public IMode
{
private:

public:
    Mode();
    ~Mode();
    void check_brightness_lvl(std::optional<uint8_t> data);
    void check_data(std::optional<std::vector<uint8_t>> data);
};

#endif