#pragma once

#include "includes.h"

namespace utils
{
    int get_fps();
    std::string utf32_to_utf8(const std::u32string &str);
    int block2col(int block);
}