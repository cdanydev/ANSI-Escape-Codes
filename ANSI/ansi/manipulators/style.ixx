export module ansi:style;

import :csi;

export namespace ansi
{
    inline namespace manipulators
    {
        constexpr csi<1> reset{0, 'm'};

        namespace style
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
}
