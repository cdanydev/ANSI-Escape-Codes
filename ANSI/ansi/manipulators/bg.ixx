export module ansi:bg;

import :csi;

export namespace ansi
{
    inline namespace manipulators
    {
        namespace bg
        {
            constexpr color4_t black{40, 'm'};
            constexpr color4_t red{41, 'm'};
            constexpr color4_t green{42, 'm'};
            constexpr color4_t yellow{43, 'm'};
            constexpr color4_t blue{44, 'm'};
            constexpr color4_t magenta{45, 'm'};
            constexpr color4_t cyan{46, 'm'};
            constexpr color4_t white{47, 'm'};

            namespace bright
            {
                constexpr color4_t black{100, 'm'};
                constexpr color4_t red{101, 'm'};
                constexpr color4_t green{102, 'm'};
                constexpr color4_t yellow{103, 'm'};
                constexpr color4_t blue{104, 'm'};
                constexpr color4_t magenta{105, 'm'};
                constexpr color4_t cyan{106, 'm'};
                constexpr color4_t white{107, 'm'};
            }

            constexpr auto set(const value_t n) -> csi<3> { return {48, 5, n, 'm'}; }
            constexpr auto set(const value_t r, const value_t g, const value_t b) -> csi<5> { return {48, 2, r, g, b, 'm'}; }
        }
    }
}
