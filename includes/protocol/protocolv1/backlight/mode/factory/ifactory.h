#ifndef IBRIGHTNESS_MODE_FACTORY_H
#define IBRIGHTNESS_MODE_FACTORY_H

#include "mode.h"


class IBrightnessModeFactory
{
private:
    /* data */
public:
    IBrightnessModeFactory(/* args */){}
    ~IBrightnessModeFactory(){}
    virtual std::unique_ptr<IMode> create_brightness_factory(std::optional<uint8_t> _register) = 0;
};

#endif


