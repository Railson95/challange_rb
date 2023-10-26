#include "../protocol/protocolv1/backlight/mode/normal_mode.h"
#define NORMAL_MODE 0x06 // Brightness level at normal mode.

NormalMode::NormalMode():Mode()
{
    this->normal_mode = NORMAL_MODE;
}

NormalMode::~NormalMode()
{

}

uint8_t NormalMode::get_valid_register()
{
    return this->normal_mode;
}