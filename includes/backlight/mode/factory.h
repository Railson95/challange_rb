#ifndef BRIGHTNESS_MODE_FACTORY_H
#define BRIGHTNESS_MODE_FACTORY_H

#include "mode.h"


class BrightnessModeFactory
{
private:
    /* data */
public:
    BrightnessModeFactory(/* args */);
    ~BrightnessModeFactory();
    Mode *create_brightness_factory(uint8_t _register);
};

#endif


