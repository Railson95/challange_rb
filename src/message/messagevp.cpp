#include "../message/messagevp.h"


MessageVP::MessageVP(uint8_t frame_header_h,
               uint8_t frame_header_l,
               uint8_t command) : Message(frame_header_h,
                                          frame_header_l,
                                          command)
{
}

MessageVP::~MessageVP()
{
}

uint16_t MessageVP::get_memory_max()
{
    return 0x6FFF;
}

uint16_t MessageVP::get_memory_address()
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

uint8_t MessageVP::calc_byte_count()
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


