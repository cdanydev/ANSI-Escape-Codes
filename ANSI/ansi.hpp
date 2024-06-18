#pragma once

#if __cplusplus >= 202002L
#   include <format>
#endif

namespace ansi
{
    typedef unsigned char value_t;

#if __cplusplus >= 202002L
    inline namespace csi
    {
        namespace caret
        {
            auto up(value_t = 1) -> std::string;
            auto down(value_t = 1) -> std::string;
            auto forward(value_t = 1) -> std::string;
            auto back(value_t = 1) -> std::string;

            auto move(value_t) -> std::string;
            auto move(value_t, value_t) -> std::string;
        }

        namespace line
        {
            auto next(value_t = 1) -> std::string;
            auto prev(value_t = 1) -> std::string;
        }

        namespace erase
        {
            auto all(value_t = 0) -> std::string;
            auto line(value_t = 0) -> std::string;
        }

        namespace scroll
        {
            auto up(value_t = 1) -> std::string;
            auto down(value_t = 1) -> std::string;
        }

        auto sgr(value_t) -> std::string;
    }
#endif

    inline namespace sgr
    {
        constexpr auto reset = "\x1b[0m";
        constexpr auto bold = "\x1b[1m";
        constexpr auto faint = "\x1b[2m";
        constexpr auto italic = "\x1b[3m";
        constexpr auto underline = "\x1b[4m";
        constexpr auto blink = "\x1b[5m";
        constexpr auto invert = "\x1b[7m";
        constexpr auto revert = "\x1b[27m";
        constexpr auto hide = "\x1b[8m";
        constexpr auto reveal = "\x1b[28m";
        constexpr auto strike = "\x1b[9m";
        constexpr auto double_underline = "\x1b[21m";
        constexpr auto overline = "\x1b[53m";

        namespace un
        {
            constexpr auto bold = "\x1b[22m";
            constexpr auto faint = "\x1b[22m";
            constexpr auto italic = "\x1b[23m";
            constexpr auto underline = "\x1b[24m";
            constexpr auto blink = "\x1b[25m";
            constexpr auto invert = "\x1b[27m";
            constexpr auto hide = "\x1b[28m";
            constexpr auto strike = "\x1b[29m";
            constexpr auto overline = "\x1b[55m";
        }

        namespace fg
        {
            constexpr auto black = "\x1b[30m";
            constexpr auto red = "\x1b[31m";
            constexpr auto green = "\x1b[32m";
            constexpr auto yellow = "\x1b[33m";
            constexpr auto blue = "\x1b[34m";
            constexpr auto magenta = "\x1b[35m";
            constexpr auto cyan = "\x1b[36m";
            constexpr auto white = "\x1b[37m";
            constexpr auto gray = "\x1b[90m";

#if __cplusplus >= 202002L
            auto set(value_t) -> std::string;
            auto set(value_t r, value_t g, value_t b) -> std::string;
#endif
            
            namespace bright
            {
                constexpr auto black = "\x1b[90m";
                constexpr auto red = "\x1b[91m";
                constexpr auto green = "\x1b[92m";
                constexpr auto yellow = "\x1b[93m";
                constexpr auto blue = "\x1b[94m";
                constexpr auto magenta = "\x1b[95m";
                constexpr auto cyan = "\x1b[96m";
                constexpr auto white = "\x1b[97m";
            }
        }

        namespace bg
        {
            constexpr auto black = "\x1b[40m";
            constexpr auto red = "\x1b[41m";
            constexpr auto green = "\x1b[42m";
            constexpr auto yellow = "\x1b[43m";
            constexpr auto blue = "\x1b[44m";
            constexpr auto magenta = "\x1b[45m";
            constexpr auto cyan = "\x1b[46m";
            constexpr auto white = "\x1b[47m";
            constexpr auto gray = "\x1b[100m";

#if __cplusplus >= 202002L
            auto set(value_t) -> std::string;
            auto set(value_t r, value_t g, value_t b) -> std::string;
#endif
            
            namespace bright
            {
                constexpr auto black = "\x1b[100m";
                constexpr auto red = "\x1b[101m";
                constexpr auto green = "\x1b[102m";
                constexpr auto yellow = "\x1b[103m";
                constexpr auto blue = "\x1b[104m";
                constexpr auto magenta = "\x1b[105m";
                constexpr auto cyan = "\x1b[106m";
                constexpr auto white = "\x1b[97m";
            }
        }
    }
}
