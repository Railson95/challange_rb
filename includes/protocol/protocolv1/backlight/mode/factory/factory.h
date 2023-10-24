#ifndef BRIGHTNESS_MODE_FACTORY_H
#define BRIGHTNESS_MODE_FACTORY_H

#include "ifactory.h"

class BrightnessModeFactory: public IBrightnessModeFactory
{
private:
    /* data */
public:
    BrightnessModeFactory(/* args */);
    ~BrightnessModeFactory();
    std::unique_ptr<IMode> create_brightness_factory(std::optional<uint8_t> _register);
};

#endif


