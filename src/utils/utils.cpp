#include "utils/utils.h"


Utils::Utils()
{

}

unsigned char * Utils::to_char_pointer(std::vector<std::optional<uint8_t>> bytes)
{
    std::vector<uint8_t> temp_bytes;
    for (const auto &opt : bytes)
    {
        if (opt.has_value())
        {
            temp_bytes.push_back(opt.value());
        }
    }
    return temp_bytes.data();
}