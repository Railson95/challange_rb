#include "../uart/uart.h"
#include <iomanip>
Uart::Uart()
{
    std::cout << "Chamou construtor da Uart.." << std::endl;
}

Uart::~Uart()
{
    // std::cout << "Chamou construtor da Uart.." << std::endl;
}

void Uart::send(unsigned char *data, size_t data_len)
{
    // Prints to screen to emulate sending to serial port
    std::cout << "Sending data to UART: 0x";
    for (int i = 0; i < data_len; i++)
    {
        std::cout << std::hex << std::setfill('0') << std::setw(2) << int(data[i]);
    }
    std::cout << " (" << data_len << " bytes)" << std::endl;
}
