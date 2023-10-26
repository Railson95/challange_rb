#include "../protocol/protocolv1/screen/message/screen.h"
#include "../protocol/protocolv1/screen/confregister/factory/factory.h"
#include "../protocol/protocolv1/igenericbyte.h"

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
    std::optional<std::unique_ptr<IGenericByte>> generic_byte = factory->create_screen_factory(get_register());

    std::optional<std::vector<uint8_t>> data = this->get_data();
    size_t byte_count = calc_byte_count();
    set_byte_count(byte_count); 
    
    this->process_and_send_data(data, generic_byte);
}
