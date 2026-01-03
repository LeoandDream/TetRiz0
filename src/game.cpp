#include "game.h"

namespace game
{
    bool running = true;
    uint8_t row, col;
    void init()
    {
        start_listening();
        terminal_control::clear_screen();
        terminal_control::hide_cursor();
        running = true;
        row = 2;
        col = 11;
    }

    void move_left()
    {
        col--;
        if (col < 11)
            col = 11;
    }

    void move_right()
    {
        col++;
        if (col > 20)
            col = 20;
    }

    void rotate()
    {
        row--;
        if (row < 1)
            row = 1;
    }

    void soft_drop()
    {
        row++;
        if (row > 11)
            row = 11;
    }

    void hard_drop()
    {
        row += 3;
        if (row > 20)
            row = 20;
    }

    void quit()
    {
        running = false;
    }
}