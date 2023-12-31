#include "../ihm/ihm.h"
#include "../protocol/factory/factory.h"

Ihm::Ihm(std::string protocol_type): IIhm()
{
    this->protocol = nullptr;
    std::unique_ptr<ProtocolFactory> protocol_factory = std::make_unique<ProtocolFactory>();
    this->protocol = protocol_factory->create_protocol(protocol_type);
}

Ihm::~Ihm()
{
    
}

uint8_t Ihm::get_backlight_level()
{
    return this->protocol->get_backlight_level();
}
void Ihm::set_backlight_level(uint8_t operation_mode, uint8_t level)
{
    this->protocol->set_backlight_level(operation_mode, level);
}

void Ihm::set_qrcode_value(int qrcode_address_vp, char *qrcode_text)
{
    this->protocol->set_qrcode_value(qrcode_address_vp, qrcode_text);
}

void Ihm::set_screen(int id)
{
    this->protocol->set_screen(id);
}

int Ihm::get_button_value(int button_address_vp)
{
    this->protocol->get_button_value(button_address_vp);
}