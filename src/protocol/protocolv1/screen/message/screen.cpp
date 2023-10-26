#include "../protocol/protocolv1/screen/message/screen.h"
#include "../protocol/protocolv1/screen/confregister/factory/factory.h"
#include "../uart/uart.h"
#include "../utils/utils.h"

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


    std::optional<std::vector<uint8_t>> data;

    data = this->get_data();

    this->set_byte_count(this->calc_byte_count());

    if(data.has_value()){
        
        byte->check_data(data);
        if(is_memory_overflow())
        {
            throw std::overflow_error("Memory Overflow! ");
        }
    }

    Uart *u = new Uart();
    Utils *utils = new Utils();
    size_t bytes_length = this->get_bytes().size();
    unsigned char * bytes = utils->to_char_pointer(this->get_bytes());
    u->send(bytes, bytes_length);
    std::cout << std::endl;


}
