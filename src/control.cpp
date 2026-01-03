#include "control.h"
#include "includes.h"

char command;

namespace game
{

    void loop()
    {

        while (true)
        {
            terminal_control::clear_screen();
            draw::draw_window(1, 1, 9, 6, "Hold");
            draw::draw_window(1, 10, 12, 22, "Tetriz");
            draw::draw_window(7, 1, 9, 16, "Status");
            draw::draw_window(19, 22, 8, 4, "Info");
            draw::draw_window(1, 22, 8, 18, "Next");
            terminal_control::move_cursor(10, 4);
            std::cout << "FPS: " << utils::get_fps() << std::endl;

            terminal_control::move_cursor(utils::block2col(row), utils::block2col(col));
            terminal_control::set_back_color(10); // green text
            std::cout << "  " << std::endl;

            terminal_control::reset_colors();
            if (!running)
                break;
            std::this_thread::sleep_for(16ms);
        }
    }

    std::map<char, std::function<void()>> command_map{
        {Key_Q, quit_command},
        {Key_W, rotate_command},
        {Key_A, move_left_command},
        {Key_D, move_right_command},
        {Key_S, soft_drop_command},
        {Key_SPACE, hard_drop_command}};

    void quit_command()
    {
        command = 'q';
        quit();
    }

    void rotate_command()
    {
        command = 'w';
        rotate();
    }

    void move_left_command()
    {
        command = 'a';
        move_left();
    }

    void move_right_command()
    {
        command = 'd';
        move_right();
    }

    void soft_drop_command()
    {
        command = 's';
        soft_drop();
    }

    void hard_drop_command()
    {
        command = ' ';
        hard_drop();
    }

    char getch()
    {
        char c;
        struct termios oldt, newt;
        tcgetattr(0, &oldt);
        newt = oldt;
        cfmakeraw(&newt);
        tcsetattr(0, 0, &newt);
        c = getchar();
        tcsetattr(0, 0, &oldt);
        return c;
    }

    void key_listener()
    {
        // Placeholder for key listening logic
        while (true)
        {
            command = getch();
            command_map[command]();
        }
    }

    void exit()
    {
        terminal_control::reset_colors();
        terminal_control::set_fore_color(9); // red text
        terminal_control::clear_screen();
        terminal_control::move_cursor(1, 1);
        terminal_control::show_cursor();
        std::cout << "\n\n\n\nBye!\n\n\n"
                  << "Thank you for playing!\n\n\n";
        terminal_control::reset_colors();
    }

    void start_listening()
    {
        std::thread key_thread(key_listener);
        key_thread.detach();
    }

} // namespace game