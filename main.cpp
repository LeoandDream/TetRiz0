#include <iostream>
#include <thread>
#include <chrono>

#include "terminal.h"
#include "utils.h"
#include "draw.h"

using namespace std::chrono_literals;

void a();

void init()
{
    terminal_control::clear_screen();
    terminal_control::hide_cursor();
    draw::draw_window(1, 1, 9, 6, "Hold");
    draw::draw_window(1, 10, 12, 22, "Tetriz");
    draw::draw_window(7, 1, 9, 16, "Status");
    draw::draw_window(19, 22, 8, 4, "Info");
    draw::draw_window(1, 22, 8, 18, "Next");
}

void loop()
{
    int line = 1;
    while (true)
    {

        // terminal_control::clear_screen();
        terminal_control::move_cursor(10, 4);
        std::cout << "FPS: " << utils::get_fps() << std::endl;
        // terminal_control::move_cursor(line, 10);
        // line++;
        // if (line > 20)
        //     line = 1;
        terminal_control::move_cursor(5, 10);
        terminal_control::set_back_color(15); // white background
        std::cout << "  " << std::endl;
        std::cout << std::flush;
        terminal_control::reset_colors();
        std::this_thread::sleep_for(100ms);
    }
}
void exit()
{
    terminal_control::reset_colors();
    terminal_control::clear_screen();
    terminal_control::move_cursor(1, 1);
    terminal_control::show_cursor();
}

int main()
{
    init();
    loop();
    exit();
    return 0;
}