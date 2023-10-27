#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <optional>
#include <cstdint>

class Utils
{
private:
    /* data */
public:
    Utils(/* args */);
    unsigned char *to_char_pointer(std::vector<uint8_t> &bytes);
};

#endif 