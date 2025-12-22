#include "utils.h"
#include <chrono>

using namespace std::chrono_literals;

int utils::get_fps()
{
    using namespace std::chrono_literals;
    static auto start_time = std::chrono::steady_clock::now();
    static uint16_t frame_count = 0;
    static uint16_t fps = 0;
    auto end_time = std::chrono::steady_clock::now();
    frame_count++;
    if (end_time - start_time >= 1s)
    {
        fps = frame_count;
        frame_count = 0;
        start_time = end_time;
    }
    return fps;
}