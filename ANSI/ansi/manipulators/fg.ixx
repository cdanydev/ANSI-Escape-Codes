export module ansi:fg;

import :csi;

export namespace ansi
{
    inline namespace manipulators
    {
        namespace fg
        {
            constexpr color4_t black{30, 'm'};
            constexpr color4_t red{31, 'm'};
            constexpr color4_t green{32, 'm'};
            constexpr color4_t yellow{33, 'm'};
            constexpr color4_t blue{34, 'm'};
            constexpr color4_t magenta{35, 'm'};
            constexpr color4_t cyan{36, 'm'};
            constexpr color4_t white{37, 'm'};

            namespace bright
            {
                constexpr color4_t black{90, 'm'};
                constexpr color4_t red{91, 'm'};
                constexpr color4_t green{92, 'm'};
                constexpr color4_t yellow{93, 'm'};
                constexpr color4_t blue{94, 'm'};
                constexpr color4_t magenta{95, 'm'};
                constexpr color4_t cyan{96, 'm'};
                constexpr color4_t white{97, 'm'};
            }

            constexpr auto set(const value_t n) -> csi<3> { return {38, 5, n, 'm'}; }
            constexpr auto set(const value_t r, const value_t g, const value_t b) -> csi<5> { return {38, 2, r, g, b, 'm'}; }
        }
    }
}
