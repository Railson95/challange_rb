#ifndef FACTORY_H
#define FACTORY_H

#include "ifactory.h"

class ProtocolFactory: public IProtocolFactory
{
private:
    /* data */
public:
    ProtocolFactory(/* args */);
    ~ProtocolFactory();
    std::unique_ptr<IProtocol> create_protocol(std::string protocol_type);
    int to_int(std::string protocol_type);
};

#endif


