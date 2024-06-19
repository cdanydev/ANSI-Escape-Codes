export module ansi:manipulators;

import std;
import :manip;

export namespace ansi::manipulators
{
    namespace caret
    {
        constexpr auto up(const value_t n = 1) -> control_t { return {n, 'A'}; }
        constexpr auto down(const value_t n = 1) -> control_t { return {n, 'B'}; }
        constexpr auto forward(const value_t n = 1) -> control_t { return {n, 'C'}; }
        constexpr auto back(const value_t n = 1) -> control_t { return {n, 'D'}; }
        constexpr auto move(const value_t row) -> control_t { return {row, 'G'}; }
        constexpr auto move(const value_t row, const value_t column) -> manip<2> { return {row, column, 'H'}; }
    }

    namespace line
    {
        constexpr auto next(const value_t n = 1) -> control_t { return {n, 'E'}; }
        constexpr auto prev(const value_t n = 1) -> control_t { return {n, 'F'}; }
    }

    namespace erase
    {
        enum erase_mode final : value_t { from_caret, to_caret, whole };

        constexpr auto all(const erase_mode how = whole) -> control_t { return {how, 'J'}; }
        constexpr auto line(const erase_mode how = whole) -> control_t { return {how, 'K'}; }
    }

    namespace scroll
    {
        constexpr auto up(const value_t n = 1) -> control_t { return {n, 'S'}; }
        constexpr auto down(const value_t n = 1) -> control_t { return {n, 'T'}; }
    }

    namespace fg
    {
        constexpr color4_t black{30, 'm'};
        constexpr color4_t red{31, 'm'};
        constexpr color4_t green{32, 'm'};
        constexpr color4_t yellow{33, 'm'};
        constexpr color4_t indigo{34, 'm'};
        constexpr color4_t magenta{35, 'm'};
        constexpr color4_t cyan{36, 'm'};
        constexpr color4_t white{37, 'm'};

        namespace bright
        {
            constexpr color4_t black{90, 'm'};
            constexpr color4_t red{91, 'm'};
            constexpr color4_t green{92, 'm'};
            constexpr color4_t yellow{93, 'm'};
            constexpr color4_t indigo{94, 'm'};
            constexpr color4_t magenta{95, 'm'};
            constexpr color4_t cyan{96, 'm'};
            constexpr color4_t white{97, 'm'};
        }

        constexpr auto set(const value_t n) -> color8_t { return {38, 5, n, 'm'}; }
        constexpr auto rgb(const value_t r, const value_t g, const value_t b) -> color24_t { return {38, 2, r, g, b, 'm'}; }
    }

    namespace bg
    {
        constexpr color4_t black{40, 'm'};
        constexpr color4_t red{41, 'm'};
        constexpr color4_t green{42, 'm'};
        constexpr color4_t yellow{43, 'm'};
        constexpr color4_t indigo{44, 'm'};
        constexpr color4_t magenta{45, 'm'};
        constexpr color4_t cyan{46, 'm'};
        constexpr color4_t white{47, 'm'};

        namespace bright
        {
            constexpr color4_t black{100, 'm'};
            constexpr color4_t red{101, 'm'};
            constexpr color4_t green{102, 'm'};
            constexpr color4_t yellow{103, 'm'};
            constexpr color4_t indigo{104, 'm'};
            constexpr color4_t magenta{105, 'm'};
            constexpr color4_t cyan{106, 'm'};
            constexpr color4_t white{107, 'm'};
        }

        constexpr auto set(const value_t n) -> color8_t { return {48, 5, n, 'm'}; }
        constexpr auto rgb(const value_t r, const value_t g, const value_t b) -> color24_t { return {48, 2, r, g, b, 'm'}; }
    }

    constexpr control_t reset{0, 'm'};

    inline namespace style
    {
        constexpr style_t bold{1, 'm'};
        constexpr style_t faint{2, 'm'};
        constexpr style_t italic{3, 'm'};
        constexpr style_t underline{4, 'm'};
        constexpr style_t blink{5, 'm'};
        constexpr style_t invert{7, 'm'};
        constexpr style_t revert{27, 'm'};
        constexpr style_t hide{8, 'm'};
        constexpr style_t reveal{28, 'm'};
        constexpr style_t strike{9, 'm'};
        constexpr style_t double_underline{21, 'm'};
        constexpr style_t overline{53, 'm'};

        namespace un
        {
            constexpr style_t bold{22, 'm'};
            constexpr style_t faint{22, 'm'};
            constexpr style_t italic{23, 'm'};
            constexpr style_t underline{24, 'm'};
            constexpr style_t blink{25, 'm'};
            constexpr style_t invert{27, 'm'};
            constexpr style_t hide{28, 'm'};
            constexpr style_t strike{29, 'm'};
            constexpr style_t overline{55, 'm'};
        }
    }
}
