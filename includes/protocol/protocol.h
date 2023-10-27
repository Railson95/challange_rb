#ifndef PROTOCOL_H
#define PROTOCOL_H

#include "iprotocol.h"


class Protocol: public IProtocol
{
private:
    uint8_t operation_mode;
public:
    Protocol(/* args */);
    ~Protocol();
    uint8_t get_operation_mode();
    void set_operation_mode(uint8_t operation_mode);
};


#endif