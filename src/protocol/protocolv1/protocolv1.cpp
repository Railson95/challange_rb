#include "../protocol/protocolv1/protocolv1.h"
#include "../protocol/protocolv1/backlight/message/backlight.h"
#include "../protocol/protocolv1/qrcode/message/qrcode.h"
#include "../protocol/protocolv1/screen/message/screen.h"
#include "../constants/constants.h"

#define BACKLIGHT_LENGHT 0x01

Protocolv1::Protocolv1()
{
}

Protocolv1::~Protocolv1()
{
}

uint8_t Protocolv1::get_backlight_level()
{
    if (get_operation_mode() == 0)
    {
        std::cout << "Operating mode not yet defined" << std::endl;
        return 0;
    }
    std::unique_ptr<Backlight> backlight =
        std::make_unique<Backlight>(FRAME_HEADER_H, FRAME_HEADER_L, READ_REGISTER);
    backlight->set_register(get_operation_mode());
    backlight->set_length(BACKLIGHT_LENGHT);
    backlight->execute();
    /*TODO: implement the correct backlight return,
    however it was not requested in the exercise*/
    return 0;
}

void Protocolv1::set_backlight_level(uint8_t operation_mode, uint8_t level)
{
    std::unique_ptr<Backlight> backlight =
        std::make_unique<Backlight>(FRAME_HEADER_H, FRAME_HEADER_L, WRITE_REGISTER);
    backlight->set_register(operation_mode);
    std::vector<uint8_t> data;
    data.push_back(level);
    backlight->set_data(data);
    this->set_operation_mode(operation_mode);
    backlight->execute();
}

void Protocolv1::set_qrcode_value(int qrcode_address_vp, char *qrcode_text)
{
    std::cout << "Send info - QRCode" << std::endl;

    std::unique_ptr<QRCode> qrcode = 
        std::make_unique<QRCode>(FRAME_HEADER_H, FRAME_HEADER_L, WRITE_VP);
    uint16_t vp_address = static_cast<uint16_t>(qrcode_address_vp);
    qrcode->set_vp_address(vp_address);
    qrcode->set_data(qrcode_text);
    qrcode->execute();
}


void Protocolv1::set_screen(int id)
{
    std::cout << "Send info - Screen" << std::endl;

    std::unique_ptr<Screen> screen = 
        std::make_unique<Screen>(FRAME_HEADER_H, FRAME_HEADER_L, WRITE_REGISTER);
    // screen->set_data(qrcode_text);
    screen->execute();
}
