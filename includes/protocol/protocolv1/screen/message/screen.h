#include "message.h"

class Screen : public Message
{
private:
    
public:
    Screen(uint8_t frame_header_h,
              uint8_t frame_header_l,
              uint8_t command);
    ~Screen();
    void execute();
};
