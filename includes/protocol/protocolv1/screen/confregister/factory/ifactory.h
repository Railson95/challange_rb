#ifndef IFACTORY_H
#define IFACTORY_H
#include <iostream>
#include <memory>
#include "ibyte.h"

class IFactoryScreen
{
private:
    /* data */
public:
    IFactoryScreen(/* args */){}
    ~IFactoryScreen(){}
    virtual std::unique_ptr<IByte> create_screen_factory(std::optional<uint8_t> _register) = 0;
};

#endif