#ifndef QRCODE_H
#define QRCODE_H

#include "message.h"

class QRCode : public Message
{
private:
    std::vector<uint8_t> vp_addrs;

public:
    QRCode(uint8_t frame_header_h,
              uint8_t frame_header_l,
              uint8_t command);
    ~QRCode();
    void execute();
    uint8_t get_memory_max();
    uint8_t get_memory_addrs();
    uint8_t calc_byte_count();
};



#endif // !1