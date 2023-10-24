#ifndef IHM_H
#define IHM_H

#include "iihm.h"
#include "../protocol/iprotocol.h"

class Ihm: public IIhm
{
private:
    std::unique_ptr<IProtocol> protocol = nullptr;
public:
    Ihm(std::string protocol_type);
    ~Ihm();
    uint8_t get_backlight_level();
    void set_backlight_level(uint8_t operation_mode, uint8_t level);
    void set_qrcode_value(int qrcode_address_vp, char *qrcode_text);
};

#endif