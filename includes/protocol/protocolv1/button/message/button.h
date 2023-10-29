#ifndef BUTTON_H
#define BUTTON_H

#include "../message/messagere.h"

class Button : public MessageRE
{
private:
    
public:
    Button(uint8_t frame_header_h,
              uint8_t frame_header_l,
              uint8_t command);
    ~Button();
    void execute();
    void set_data(char *data);
    void set_vp_address(std::optional<uint16_t> vp_address);
};


#endif