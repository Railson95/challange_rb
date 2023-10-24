#ifndef IFACTORY_H
#define IFACTORY_H

#include "../iprotocol.h"
#include <string>

class IProtocolFactory
{
private:
    /* data */
public:
    IProtocolFactory(/* args */){}
    ~IProtocolFactory(){}
    virtual IProtocol *create_protocol(std::string protocol_type) = 0;
    virtual int to_int(std::string protocol_type) = 0;
};

#endif


