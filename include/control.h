#pragma once

#include "includes.h"

namespace game
{
    void loop();
    void exit();
    char getch();
    void key_listener();
    void start_listening();
    void quit_command();
    void rotate_command();
    void move_left_command();
    void move_right_command();
    void soft_drop_command();
    void hard_drop_command();
}