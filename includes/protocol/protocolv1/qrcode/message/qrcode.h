#ifndef QRCODE_H
#define QRCODE_H

#include "messagevp.h"

class QRCode : public MessageVP
{
private:
    
public:
    QRCode(uint8_t frame_header_h,
              uint8_t frame_header_l,
              uint8_t command);
    ~QRCode();
    void execute();
    void set_data(char *data);
    void set_vp_address(std::optional<uint16_t> vp_address);
};

#endif