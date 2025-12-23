#include "draw.h"
#include "terminal.h"
#include <iostream>

/**
        0	1	2	3	4	5	6	7	8	9	A	B	C	D	E	F
U+250x	─	━	│	┃	┄	┅	┆	┇	┈	┉	┊	┋	┌	┍	┎	┏
U+251x	┐	┑	┒	┓	└	┕	┖	┗	┘	┙	┚	┛	├	┝	┞	┟
U+252x	┠	┡	┢	┣	┤	┥	┦	┧	┨	┩	┪	┫	┬	┭	┮	┯
U+253x	┰	┱	┲	┳	┴	┵	┶	┷	┸	┹	┺	┻	┼	┽	┾	┿
U+254x	╀	╁	╂	╃	╄	╅	╆	╇	╈	╉	╊	╋	╌	╍	╎	╏
U+255x	═	║	╒	╓	╔	╕	╖	╗	╘	╙	╚	╛	╜	╝	╞	╟
U+256x	╠	╡	╢	╣	╤	╥	╦	╧	╨	╩	╪	╫	╬	╭	╮	╯
U+257x	╰	╱	╲	╳	╴	╵	╶	╷	╸	╹	╺	╻	╼	╽	╾	╿
 */

namespace draw
{

    inline int block2col(int block)
    {
        return 2 * block - 1;
    }

    void draw_window(int top, int left, int width, int height, std::string title)
    {
        for (int row = 0; row < height; row++)
        {
            terminal_control::move_cursor(top + row, block2col(left));
            for (int col = 0; col < width; col++)
            {
                if (row == 0)
                {
                    if (col == 0)
                    {
                        std::cout << " ┌";
                    }
                    else if (col == width - 1)
                    {
                        std::cout << "┐";
                    }
                    else
                    {
                        std::cout << "──";
                    }
                }
                else if (row == height - 1)
                {
                    if (col == 0)
                    {
                        std::cout << " └";
                    }
                    else if (col == width - 1)
                    {
                        std::cout << "┘";
                    }
                    else
                    {
                        std::cout << "──";
                    }
                }
                else
                {
                    if (col == 0)
                    {
                        std::cout << " │";
                    }
                    else if (col == width - 1)
                    {
                        std::cout << "│";
                    }
                    else
                    {
                        std::cout << "  ";
                    }
                }
            }
        }
        terminal_control::move_cursor(top, block2col(left) + (width * 2 - title.length()) / 2);
        std::cout << title;
    }

}