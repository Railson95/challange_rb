#ifndef FACTORY_H
#define FACTORY_H
#include <optional>
#include "ifactory.h"


class FactoryScreen: public IFactoryScreen
{
private:
    /* data */
public:
    FactoryScreen(/* args */);
    ~FactoryScreen();
    std::unique_ptr<IByte> create_screen_factory(std::optional<uint8_t> _register);
};

#endif