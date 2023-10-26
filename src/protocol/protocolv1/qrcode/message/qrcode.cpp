
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
    std::optional<std::vector<uint8_t>> data = this->get_data();
    std::optional<std::unique_ptr<IGenericByte>> opcional1 = std::nullopt;
    size_t byte_count = calc_byte_count();
    set_byte_count(byte_count); 

    this->process_and_send_data(data, opcional1);
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
    return this->get_vp_address().value();
}

uint8_t QRCode::calc_byte_count()
{
    const std::type_info& tipo = typeid(this);
    std::string class_name = tipo.name();
    uint8_t size_vp = (!this->split_vp_address().empty())? this->split_vp_address().size():0;
    uint8_t size_data = (this->get_data().has_value())? this->get_data().value().size():0; 
    size_t lenght_cmd = 1;

    if(!this->get_vp_address().has_value()){
        std::cout << "Invalid vp address {" << class_name << "}" << std::endl;
        return 0;
    }
    return size_vp + size_data + lenght_cmd;
}

