#include "../protocol/protocolv1/button/message/button.h"
#include "../message/messagere.h"

Button::Button(uint8_t frame_header_h,
               uint8_t frame_header_l,
               uint8_t command) : MessageRE(frame_header_h,
                                          frame_header_l,
                                          command)
{
}

Button::~Button()
{
}

void Button::execute()
{
    std::optional<std::vector<uint8_t>> data = this->get_data();
    std::optional<std::unique_ptr<IGenericByte>> opcional1 = std::nullopt;
    size_t byte_count = calc_byte_count();
    set_byte_count(byte_count); 

    this->process_and_send_data(data, opcional1);
}

void Button::set_data(char *data)
{
    Message::set_data(data);
}

void Button::set_vp_address(std::optional<uint16_t> vp_address)
{
    Message::set_vp_address(vp_address);
}