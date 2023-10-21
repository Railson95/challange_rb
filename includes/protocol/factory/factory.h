#ifndef FACTORY_H
#define FACTORY_H

#include "../iprotocol.h"
#include <string>

class ProtocolFactory
{
private:
    /* data */
public:
    ProtocolFactory(/* args */);
    ~ProtocolFactory();
    IProtocol *create_protocol(std::string protocol_type);
    int to_int(std::string protocol_type);
};

#endif


