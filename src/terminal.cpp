#include "terminal.h"

#define CSI "\033["

/**
 * @brief 均是大小写敏感的ansi终端控制函数实现
 *
 */
void terminal_control::move_cursor(int row, int col)
{
    std::cout << CSI << row << ";" << col << "H";
}

void terminal_control::set_fore_color(int color_id)
{
    std::cout << CSI << "38;5;" << color_id << "m";
}

void terminal_control::set_back_color(int color_id)
{
    std::cout << CSI << "48;5;" << color_id << "m";
}

void terminal_control::clear_screen()
{
    std::cout << CSI << "2J";
}

void terminal_control::reset_colors()
{
    std::cout << CSI << "0m";
}

void terminal_control::show_cursor()
{
    std::cout << CSI << "?25h";
}

void terminal_control::hide_cursor()
{
    std::cout << CSI << "?25l";
}