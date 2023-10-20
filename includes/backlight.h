#include "message.h"

class Backlight : public Message
{
private:
    uint8_t _register;
    uint16_t data;

public:
    Backlight(uint8_t frame_header_h,
              uint8_t frame_header_l,
              uint8_t byte_count,
              uint8_t command,
              uint8_t _register,
              uint16_t data);
    ~Backlight();
    std::vector<uint8_t> get_bytes();
    void check_brightness_lvl(uint16_t data);
    void check_brightness_period(uint16_t data);
    void check_register(uint8_t _register);
    void check_mode(uint8_t _register, uint16_t data);
    void execute();
};
