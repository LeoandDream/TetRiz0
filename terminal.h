#ifndef TERMINAL_H
#define TERMINAL_H

namespace tc
{
    // Terminal control
    void move_cursor(int row, int col);
    void set_fore_color(int color_id);
    void set_back_color(int color_id);
    void clear_screen();
    void reset_colors();
    void show_cursor();
    void hide_cursor();
}

#endif // TERMINAL_H