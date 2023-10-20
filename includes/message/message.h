#include <optional>
#include "imessage.h"

class Message: public IMessage
{
private:
    uint8_t frame_header_h;
    uint8_t frame_header_l;
    uint8_t byte_count;
    uint8_t command;
    std::optional<uint8_t> _register;
    std::optional<uint16_t> data;

public:
    Message(uint8_t frame_header_h,
            uint8_t frame_header_l,
            uint8_t byte_count,
            uint8_t command,
            std::optional<uint8_t> _register,
            std::optional<uint16_t> data);
    ~Message();
    uint8_t get_frame_header_h();
    uint8_t get_frame_header_l();
    uint8_t get_byte_count();
    uint8_t get_command();
    void execute();
    
};
