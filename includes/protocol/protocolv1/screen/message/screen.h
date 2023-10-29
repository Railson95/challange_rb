#include "messagere.h"

class Screen : public MessageRE
{
private:
    
public:
    Screen(uint8_t frame_header_h,
              uint8_t frame_header_l,
              uint8_t command);
    ~Screen();
    void execute();
    void set_data(std::optional<std::vector<uint8_t>> data);
    void set_register(std::optional<uint8_t> _register);
};
