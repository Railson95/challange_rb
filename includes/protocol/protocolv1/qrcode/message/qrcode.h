#ifndef QRCODE_H
#define QRCODE_H

#include "message.h"

class QRCode : public Message
{
private:
    
public:
    QRCode(uint8_t frame_header_h,
              uint8_t frame_header_l,
              uint8_t command);
    ~QRCode();
    void execute();
    uint16_t get_memory_max();
    uint16_t get_memory_address();
    uint8_t calc_byte_count();
};



#endif // !1