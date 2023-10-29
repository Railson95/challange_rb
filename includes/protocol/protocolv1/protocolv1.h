#ifndef PROTOCOLV1_H
#define PROTOCOLV1_H

#include "../protocol/protocol.h"


class Protocolv1: public Protocol
{
private:

public:
    Protocolv1(/* args */);
    ~Protocolv1();
    uint8_t get_backlight_level();
    void set_backlight_level(uint8_t operation_mode, uint8_t level);
    void set_qrcode_value(int qrcode_address_vp, char *qrcode_text);
    void set_screen(int id);
    int get_button_value(int button_address_vp);
};

#endif
