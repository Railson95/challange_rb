#ifndef UART_H
#define UART_H
#include <iostream>

class Uart
{
private:
    /* data */
public:
    Uart(/* args */);
    ~Uart();
    void send(unsigned char *data, size_t data_len);
};

#endif // !1