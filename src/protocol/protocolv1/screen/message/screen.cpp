#include "../protocol/protocolv1/screen/message/screen.h"
#include "../protocol/protocolv1/screen/confregister/factory/factory.h"

Screen::Screen(uint8_t frame_header_h,
               uint8_t frame_header_l,
               uint8_t command) : Message(frame_header_h,
                                          frame_header_l,
                                          command)
{
}

Screen::~Screen()
{
}

void Screen::execute()
{
    std::cout << "Chamou execute Screen" << std::endl;

    std::unique_ptr<FactoryScreen> factory = std::make_unique<FactoryScreen>();
    std::unique_ptr<IByte> byte = factory->create_screen_factory(get_register());

}

uint16_t Screen::get_memory_max()
{

}

uint16_t Screen::get_memory_address()
{

}

uint8_t Screen::calc_byte_count()
{

}