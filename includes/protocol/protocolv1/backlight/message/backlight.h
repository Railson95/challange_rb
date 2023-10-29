#include "messagere.h"

class Backlight : public MessageRE
{
private:

public:
    Backlight(uint8_t frame_header_h,
              uint8_t frame_header_l,
              uint8_t command);
    ~Backlight(); 
    void execute();
    void set_data(std::optional<std::vector<uint8_t>> data);
    void set_register(std::optional<uint8_t> _register);
};
