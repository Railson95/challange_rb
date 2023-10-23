
#include "../protocol/protocolv1/qrcode/message/qrcode.h"

QRCode::QRCode(uint8_t frame_header_h,
               uint8_t frame_header_l,
               uint8_t command) : Message(frame_header_h,
                                          frame_header_l,
                                          command)
{
}

QRCode::~QRCode()
{
}

void QRCode::execute()
{
}

uint8_t QRCode::get_memory_max()
{
}

uint8_t QRCode::get_memory_addrs()
{
}

uint8_t QRCode::calc_byte_count()
{
}