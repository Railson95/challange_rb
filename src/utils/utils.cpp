#include "utils/utils.h"
#include <vector>
#include <iostream>
Utils::Utils()
{

}

unsigned char *Utils::to_char_pointer(std::vector<uint8_t> &bytes)
{
    return bytes.data();
}


