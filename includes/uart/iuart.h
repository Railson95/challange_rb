#ifndef IUART_H
#define IUART_H
#include <cstdint>
#include <cstddef>

class IUart
{
private:
    /* data */
public:
    IUart(/* args */){}
    ~IUart(){}
    virtual void send(unsigned char *data, size_t data_len) = 0;
};

#endif 