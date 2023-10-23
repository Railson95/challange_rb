#ifndef IIHM_H
#define IIHM_H

#include <cstdint>
#include <iostream>

class IIhm
{
private:

public:
    IIhm(){}
    ~IIhm(){}
    virtual uint8_t get_backlight_level() = 0;
    virtual void set_backlight_level(uint8_t operation_mode, uint8_t level) = 0;
    virtual void set_qrcode_value(int qrcode_address_vp, char *qrcode_text) = 0;
};

#endif