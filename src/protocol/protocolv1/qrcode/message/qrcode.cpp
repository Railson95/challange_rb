
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
    std::optional<std::vector<uint8_t>> data;

    data = this->get_data();

    this->set_byte_count(this->calc_byte_count());

    if(data.has_value()){
        if(is_memory_overflow())
        {
            throw std::overflow_error("Memory Overflow! ");
        }
    }

    std::cout << "Escreve bytes na UART: ";
    for (auto bytes : this->get_bytes())
    {
        std::cout << "[" << static_cast<int>(*bytes) << " ]";
    }
    std::cout << std::endl;
}

uint16_t QRCode::get_memory_max()
{
    return 0x6FFF;
}

uint16_t QRCode::get_memory_address()
{
    const std::type_info& tipo = typeid(this);
    std::string class_name = tipo.name();

    if(!this->get_vp_address().has_value())
    {
        std::cout << "Invalid vp address {" << class_name << "}" << std::endl;
        return 0;
    }
    return this->get_vp_address().value().front();
}

uint8_t QRCode::calc_byte_count()
{
    return 0;
}

