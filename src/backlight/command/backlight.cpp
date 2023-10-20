#include "../backlight/command/backlight.h"
#include "../backlight/mode/factory.h"

#include <iostream>
#define REGISTER_MIN 0x06
#define REGISTER_MAX 0x08

Backlight::Backlight(uint8_t frame_header_h,
                     uint8_t frame_header_l,
                     uint8_t byte_count,
                     uint8_t command) : Message(frame_header_h,
                                                frame_header_l,
                                                byte_count,
                                                command)

{
    std::cout << "Chamou construtor do backlight" << std::endl;
}

Backlight::~Backlight() {}

void Backlight::execute()
{
    BrightnessModeFactory *factory = new BrightnessModeFactory();
    factory->create_brightness_factory(get_register())->execute(get_data());
    delete factory;
}