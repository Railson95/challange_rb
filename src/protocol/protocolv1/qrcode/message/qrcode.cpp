
#include "../protocol/protocolv1/qrcode/message/qrcode.h"
#include "../message/messagevp.h"
#include "../message/message.h"

QRCode::QRCode(uint8_t frame_header_h,
               uint8_t frame_header_l,
               uint8_t command) : MessageVP(frame_header_h,
                                          frame_header_l,
                                          command)
{
}

QRCode::~QRCode()
{
}

void QRCode::execute()
{
    std::optional<std::vector<uint8_t>> data = this->get_data();
    std::optional<std::unique_ptr<IGenericByte>> opcional1 = std::nullopt;
    size_t byte_count = calc_byte_count();
    set_byte_count(byte_count); 

    this->process_and_send_data(data, opcional1);
}

void QRCode::set_data(char *data)
{
    Message::set_data(data);
}

void QRCode::set_vp_address(std::optional<uint16_t> vp_address)
{
    Message::set_vp_address(vp_address);
}



