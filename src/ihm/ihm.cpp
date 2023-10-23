#include "../ihm/ihm.h"
#include "../protocol/factory/factory.h"

Ihm::Ihm(std::string protocol_type): IIhm()
{
    ProtocolFactory *protocol_factory = new ProtocolFactory();
    this->protocol = protocol_factory->create_protocol(protocol_type);
    delete protocol_factory;
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