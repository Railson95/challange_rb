
#include "../protocol/protocolv1/screen/confpicid/byte.h"
#include <typeinfo>
#include <string>
#include <optional>
#include <iostream>

Byte::Byte()
{
    this->min_pic_id = 0x00;
    this->max_pic_id = 0xFF;
}

Byte::~Byte()
{
    
}

void Byte::check_data(std::optional<std::vector<uint8_t>> data){
    const std::type_info& tipo = typeid(this);
    std::string class_name = tipo.name();
    if(!data.has_value()) {
        std::cout << "Invalid data {" << class_name << "}" << std::endl;
        return;
    }  
    for(auto d: data.value())
    {    
        check_pic_id(d);
    } 
}

void Byte::check_pic_id(std::optional<uint8_t> data)
{

    if (!(data >= get_min_pic_id() && data <= get_max_pic_id()))
    {
        throw std::out_of_range("Invalid pic id image! ");
    }
}


uint8_t Byte::get_min_pic_id()
{
    return this->min_pic_id;
}


uint8_t Byte::get_max_pic_id()
{
    return this->max_pic_id;
}
