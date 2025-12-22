#include <iostream>
#include <thread>
#include <chrono>
#include "terminal.h"

void a();

int main()
{
    // std::cout << "\033[5;10H" << "\033[38;5;214m" << "Hello World!" << "\033[10;1H" << std::endl;
    // tc::move_cursor(5, 10);
    // tc::set_fore_color(214);
    // std::cout << "Hello World!" << std::endl;
    // tc::move_cursor(10, 1);
    int line = 1;
    while (true)
    {
        tc::move_cursor(line, 10);
        line++;
        if (line > 20)
            line = 1;
        tc::set_back_color(15); // white background
        std::cout << "  " << std::endl;
        std::cout << std::flush;
        tc::reset_colors();
        tc::clear_screen();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}