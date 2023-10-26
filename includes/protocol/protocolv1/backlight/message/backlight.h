#include "message.h"

class Backlight : public Message
{
private:

public:
    Backlight(uint8_t frame_header_h,
              uint8_t frame_header_l,
              uint8_t command);
    ~Backlight(); 
    void execute();
};
