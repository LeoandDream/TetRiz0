#include "draw.h"

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
    const std::u32string style1 = U" ┌┐└┘│─";
    const std::u32string style2 = U" ╔╗╚╝║═";
    const std::u32string style3 = U" ╭╮╰╯│─";
    const std::u32string style4 = U" ╒╕╘╛│═";
    const std::u32string style5 = U" ┏┓┗┛┃━";
    std::u32string cur_style = style2;

    void draw_window(int top, int left, int width, int height, std::string title)
    {
        for (int row = 0; row < height; row++)
        {
            terminal_control::move_cursor(top + row, utils::block2col(left));
            for (int col = 0; col < width; col++)
            {
                if (row == 0) // 第一行
                {
                    if (col == 0) // 第一列
                    {
                        std::cout << utils::utf32_to_utf8({cur_style[0], cur_style[1]});
                    }
                    else if (col == width - 1) // 最后一列
                    {
                        std::cout << utils::utf32_to_utf8({cur_style[2]});
                    }
                    else
                    {
                        std::cout << utils::utf32_to_utf8({cur_style[6], cur_style[6]});
                    }
                }
                else if (row == height - 1) // 最后一行
                {
                    if (col == 0) // 第一列
                    {
                        std::cout << utils::utf32_to_utf8({cur_style[0], cur_style[3]});
                    }
                    else if (col == width - 1) // 最后一列
                    {
                        std::cout << utils::utf32_to_utf8({cur_style[4]});
                    }
                    else
                    {
                        std::cout << utils::utf32_to_utf8({cur_style[6], cur_style[6]});
                    }
                }
                else
                {
                    if (col == 0)
                    {
                        std::cout << utils::utf32_to_utf8({cur_style[0], cur_style[5]});
                    }
                    else if (col == width - 1)
                    {
                        std::cout << utils::utf32_to_utf8({cur_style[5]});
                    }
                    else
                    {
                        std::cout << utils::utf32_to_utf8({cur_style[0], cur_style[0]});
                    }
                }
            }
        }
        terminal_control::move_cursor(top, utils::block2col(left) + (width * 2 - title.length()) / 2);
        std::cout << title;
    }

}