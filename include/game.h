#pragma once
#include "includes.h"

namespace game
{
    extern bool running;
    extern uint8_t row, col;
    void init();
    void move_left();
    void move_right();
    void rotate();
    void soft_drop();
    void hard_drop();
    void quit();
}