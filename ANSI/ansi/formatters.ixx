export module ansi:formatters;

import std;

namespace ansi
{
    using color_t = char8_t;

    struct color final
    {
        enum color_value final : color_t
        {
            none,
            black = 30,
            red,
            green,
            yellow,
            indigo,
            magenta,
            cyan,
            white,
            bright_black = 90,
            bright_red,
            bright_green,
            bright_yellow,
            bright_indigo,
            bright_magenta,
            bright_cyan,
            bright_white
        };

        enum color_mode final : color_t
        {
            bit4,
            bit8,
            bit24
        };
    };

    export constexpr color colors;
}

export template <>
struct std::formatter<ansi::color>
{
    constexpr auto parse(std::format_parse_context& ctx) -> std::format_parse_context::const_iterator
    {
        using ansi::color;
        
        auto pos = ctx.begin();

        if (*pos == ':')
        {
            fg = false;
            ++pos;
        }

        switch (*pos)
        {
        case 'b':
            color_value.value = color::black;
            break;
        case 'r':
            color_value.value = color::red;
            break;
        case 'g':
            color_value.value = color::green;
            break;
        case 'y':
            color_value.value = color::yellow;
            break;
        case 'i':
            color_value.value = color::indigo;
            break;
        case 'm':
            color_value.value = color::magenta;
            break;
        case 'c':
            color_value.value = color::cyan;
            break;
        case 'w':
            color_value.value = color::white;
            break;
        case 'B':
            color_value.value = color::bright_black;
            break;
        case 'R':
            color_value.value = color::bright_red;
            break;
        case 'G':
            color_value.value = color::bright_green;
            break;
        case 'Y':
            color_value.value = color::bright_yellow;
            break;
        case 'I':
            color_value.value = color::bright_indigo;
            break;
        case 'M':
            color_value.value = color::bright_magenta;
            break;
        case 'C':
            color_value.value = color::bright_cyan;
            break;
        case 'W':
            color_value.value = color::bright_white;
            break;
        default:
            mode = color::bit8;
            color_value.code = 0;

            while (pos != ctx.end() && *pos != '}')
            {
                color_value.code *= 10;
                color_value.code += *pos++ - '0';

                if (*pos == ':')
                {
                    mode = color::bit24;
                    break;
                }
            }

            if (mode == color::bit24)
            {
                std::size_t color_index = 1;
                color_value.rgb[color_index] = 0;

                while (*++pos != '}')
                {
                    if (*pos == ':')
                        color_value.rgb[++color_index] = 0;
                    else
                    {
                        color_value.rgb[color_index] *= 10;
                        color_value.rgb[color_index] += *pos - '0';
                    }
                }
            }

            return pos;
        }

        return ++pos;
    }

    auto format(const ansi::color&, std::format_context& ctx) const -> std::format_context::iterator
    {
        switch (mode)
        {
        case ansi::color::bit4:
            return std::format_to(ctx.out(), "\x1b[{}m", static_cast<int>(color_value.value) + 10 * !fg);
        case ansi::color::bit8:
            return std::format_to(ctx.out(), "\x1b[{};5;{}m", fg ? 38 : 48, static_cast<int>(color_value.code));
        case ansi::color::bit24:
            return std::format_to(ctx.out(), "\x1b[{};2;{};{};{}m", fg ? 38 : 48, static_cast<int>(color_value.rgb[0]), static_cast<int>(color_value.rgb[1]),
                                  static_cast<int>(color_value.rgb[2]));
        }

        return std::format_to(ctx.out(), "x1b[m");
    }

    union
    {
        ansi::color::color_value value;
        ansi::color_t code;
        ansi::color_t rgb[3];
    } color_value;

    ansi::color::color_mode mode = ansi::color::bit4;
    bool fg = true;
};
