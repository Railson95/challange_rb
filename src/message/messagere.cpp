#include "../message/messagere.h"


MessageRE::MessageRE(uint8_t frame_header_h,
               uint8_t frame_header_l,
               uint8_t command) : Message(frame_header_h,
                                          frame_header_l,
                                          command)
{
}

MessageRE::~MessageRE()
{
}

uint8_t MessageRE::calc_byte_count()
{
    uint8_t size_lenght = (this->get_lenght().has_value()) ? 1 : 0;
    uint8_t size_data = (this->get_data().has_value()) ? this->get_data().value().size() : 0;
    size_t cmd_reg = 2; // lenght cmd plus register

    if (this->get_lenght().has_value() && this->get_data().has_value())
    {
        return size_lenght + size_data + cmd_reg;
    }

    if (this->get_lenght().has_value())
    {
        return size_lenght + cmd_reg;
    }

    if (this->get_data().has_value())
    {
        return this->get_data().value().size() + cmd_reg;
    }
    return 0;
}

uint16_t MessageRE::get_memory_max()
{
    return 0xFF;
}

uint16_t MessageRE::get_memory_address()
{
    std::optional<uint8_t> _register = get_register();
    if (!_register.has_value())
    {
        std::cout << "Invalid Register! " << std::endl;
        return true;
    }
    return _register.value();
}

