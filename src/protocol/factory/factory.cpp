#include "../protocol/factory/factory.h"
#include "../protocol/protocolv1/protocolv1.h"

ProtocolFactory::ProtocolFactory()
{

}

ProtocolFactory::~ProtocolFactory()
{
    
}

IProtocol *ProtocolFactory::create_protocol(std::string protocol_type)
{
    Protocolv1 *protocolv1 = new Protocolv1(); 

    int result = to_int(protocol_type); 

    switch (result)
    {
    case 1:
        return protocolv1;
        break;
    
    default:
        throw std::invalid_argument("Invalid protocoltype {" + protocol_type + "}");
        break;
    }
}

int ProtocolFactory::to_int(std::string protocol_type)
{
    if("protocolv1" == protocol_type) return 1;
    return 0;
}
