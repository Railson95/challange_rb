#include "../protocol/protocolv1/backlight/message/backlight.h"
#include "../protocol/protocolv1/backlight/mode/factory/factory.h"
#include "../protocol/protocolv1/igenericbyte.h"
#include <iostream>


Backlight::Backlight(uint8_t frame_header_h,
                     uint8_t frame_header_l,
                     uint8_t command) : MessageRE(frame_header_h,
                                                frame_header_l,
                                                command)

{
}

Backlight::~Backlight() {}

void Backlight::execute()
{
    std::unique_ptr<BrightnessModeFactory> factory = std::make_unique<BrightnessModeFactory>();
    std::optional<std::unique_ptr<IGenericByte>> generic_byte = factory->create_brightness_factory(get_register());

    std::optional<std::vector<uint8_t>> data = this->get_data();
    
    size_t byte_count = calc_byte_count();
    set_byte_count(byte_count); 

    this->process_and_send_data(data, generic_byte);

}

void Backlight::set_data(std::optional<std::vector<uint8_t>> data)
{
    Message::set_data(data);
}

void Backlight::set_register(std::optional<uint8_t> _register)
{
    Message::set_register(_register);
}

