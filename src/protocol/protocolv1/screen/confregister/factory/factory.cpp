#include "../protocol/protocolv1/screen/confregister/ibyte.h"
#include "../protocol/protocolv1/screen/confregister/highbyte.h"
#include "../protocol/protocolv1/screen/confregister/lowbyte.h"
#include "../protocol/protocolv1/screen/confregister/factory/factory.h"

FactoryScreen::FactoryScreen()
{

}

FactoryScreen::~FactoryScreen()
{
    
}

std::unique_ptr<IByte> FactoryScreen::create_screen_factory(std::optional<uint8_t> _register)
{

    std::unique_ptr<IByte> high = std::make_unique<HighByteRegister>();
    std::unique_ptr<IByte> low = std::make_unique<LowByteRegister>();

    int result_register =  static_cast<int>(*_register);
    int result_high = high->get_valid_register();
    int result_low = low->get_valid_register();

    if(!(result_register >= result_high && result_register <= result_low))
    {
         throw std::out_of_range("Invalid register!");
    }

    if(result_high == result_register)
    {
        return high;
    }

    if(result_high == result_register)
    {
        return low;
    }

}