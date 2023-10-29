#include "../protocol/protocolv1/screen/message/screen.h"
#include "../protocol/protocolv1/screen/confpicid/factory/factory.h"
#include "../protocol/protocolv1/igenericbyte.h"
#include "../message/message.h"

Screen::Screen(uint8_t frame_header_h,
               uint8_t frame_header_l,
               uint8_t command) : MessageRE(frame_header_h,
                                          frame_header_l,
                                          command)
{
}

Screen::~Screen()
{
}

void Screen::execute()
{
    std::unique_ptr<FactoryScreen> factory = std::make_unique<FactoryScreen>();
    std::optional<std::unique_ptr<IGenericByte>> generic_byte = factory->create_screen_factory(get_register());

    std::optional<std::vector<uint8_t>> data = this->get_data();
    size_t byte_count = calc_byte_count();
    set_byte_count(byte_count); 
    
    this->process_and_send_data(data, generic_byte);
}

void Screen::set_data(std::optional<std::vector<uint8_t>> data)
{
    Message::set_data(data);
}

void Screen::set_register(std::optional<uint8_t> _register)
{
    Message::set_register(_register);
}
