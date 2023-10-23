#include "message.h"

class Backlight : public Message
{
private:
    uint8_t _register;

public:
    Backlight(uint8_t frame_header_h,
              uint8_t frame_header_l,
              uint8_t command);
    ~Backlight();
    void execute();
    uint8_t get_memory_max();
    uint8_t get_memory_addrs();
    uint8_t calc_byte_count();
};
