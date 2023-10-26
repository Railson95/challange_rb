
#include "../protocol/protocolv1/backlight/mode/mode.h"
#include <typeinfo>
#define BRIGHTNESS_MIN 0x00
#define BRIGHTNESS_MAX 0x3F

Mode::Mode()
{
    
}

Mode::~Mode()
{
    
}

void Mode::check_data(std::optional<std::vector<uint8_t>> data){
    const std::type_info& tipo = typeid(this);
    std::string class_name = tipo.name();
    if(!data.has_value()) {
        std::cout << "Invalid data {" << class_name << "}" << std::endl;
        return;
    }  
    for(auto d: data.value())
    {    
        check_brightness_lvl(d);
    } 
}

void Mode::check_brightness_lvl(std::optional<uint8_t> data)
{
    if (!(data >= BRIGHTNESS_MIN && data <= BRIGHTNESS_MAX))
    {
        throw std::out_of_range("Invalid brightness level! ");
    }
}


