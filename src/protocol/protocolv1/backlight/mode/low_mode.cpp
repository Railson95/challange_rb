#include "../protocol/protocolv1/backlight/mode/low_mode.h"
#define LOW_MODE 0x07    // Brightness level at low-brightness mode


LowMode::LowMode():Mode()
{
    this->low_mode = LOW_MODE;
}

LowMode::~LowMode()
{

}


uint8_t LowMode::get_valid_register()
{
    return this->low_mode;
}
