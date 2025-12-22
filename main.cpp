#include <iostream>
#include <thread>
#include <chrono>
#include "terminal.h"
#include "utils.h"

using namespace std::chrono_literals;

void a();

void init()
{
    tc::hide_cursor();
}

void loop()
{
    int line = 1;
    while (true)
    {

        tc::clear_screen();
        tc::move_cursor(2, 1);
        std::cout << "FPS: " << utils::get_fps() << std::endl;
        tc::move_cursor(line, 10);
        line++;
        if (line > 20)
            line = 1;
        tc::set_back_color(15); // white background
        std::cout << "  " << std::endl;
        std::cout << std::flush;
        tc::reset_colors();
        std::this_thread::sleep_for(100ms);
    }
}
void exit()
{
    tc::reset_colors();
    tc::clear_screen();
    tc::move_cursor(1, 1);
    tc::show_cursor();
}

int main()
{
    init();
    loop();
    exit();
    return 0;
}