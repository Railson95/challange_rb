#include "../protocol/protocol.h"


Protocol::Protocol()
{

}

Protocol::~Protocol()
{
    
}

uint8_t Protocol::get_operation_mode()
{
    return this->operation_mode;
}

void Protocol::set_operation_mode(uint8_t operation_mode)
{
    this->operation_mode = operation_mode;
}
