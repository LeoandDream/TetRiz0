#include "terminal.h"
#include <iostream>

#define CSI "\033["

/**
 * @brief 均是大小写敏感的ansi终端控制函数实现
 *
 */
void tc::move_cursor(int row, int col)
{
    std::cout << CSI << row << ";" << col << "H";
}

void tc::set_fore_color(int color_id)
{
    std::cout << CSI << "38;5;" << color_id << "m";
}

void tc::set_back_color(int color_id)
{
    std::cout << CSI << "48;5;" << color_id << "m";
}

void tc::clear_screen()
{
    std::cout << CSI << "2J";
}

void tc::reset_colors()
{
    std::cout << CSI << "0m";
}

void tc::show_cursor()
{
    std::cout << CSI << "?25h";
}

void tc::hide_cursor()
{
    std::cout << CSI << "?25l";
}