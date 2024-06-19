export module ansi:manipulators;

import std;

namespace ansi
{
    using color_t = char8_t;

    template <std::size_t N>
    struct csi
    {
        color_t value[N];
        char type;
    };

    using style_t = csi<1>;
    using color4_t = csi<1>;
    using color8_t = csi<3>;
    using color24_t = csi<5>;

    export inline namespace manipulators
    {
        namespace caret
        {
            constexpr auto up(const color_t n = 1) -> csi<1> { return {n, 'A'}; }
            constexpr auto down(const color_t n = 1) -> csi<1> { return {n, 'B'}; }
            constexpr auto forward(const color_t n = 1) -> csi<1> { return {n, 'C'}; }
            constexpr auto back(const color_t n = 1) -> csi<1> { return {n, 'D'}; }
            constexpr auto move(const color_t row) -> csi<1> { return {row, 'G'}; }
            constexpr auto move(const color_t row, const color_t column) -> csi<2> { return {row, column, 'H'}; }
        }

        namespace line
        {
            constexpr auto next(const color_t n = 1) -> csi<1> { return {n, 'E'}; }
            constexpr auto prev(const color_t n = 1) -> csi<1> { return {n, 'F'}; }
        }

        namespace erase
        {
            enum erase_mode final : color_t { from_caret, to_caret, whole };

            constexpr auto all(const erase_mode n = whole) -> csi<1> { return {n, 'J'}; }
            constexpr auto line(const erase_mode n = whole) -> csi<1> { return {n, 'K'}; }
        }

        namespace scroll
        {
            constexpr auto up(const color_t n = 1) -> csi<1> { return {n, 'S'}; }
            constexpr auto down(const color_t n = 1) -> csi<1> { return {n, 'T'}; }
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

            constexpr auto set(const color_t n) -> csi<3> { return {38, 5, n, 'm'}; }
            constexpr auto set(const color_t r, const color_t g, const color_t b) -> csi<5> { return {38, 2, r, g, b, 'm'}; }
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

            constexpr auto set(const color_t n) -> csi<3> { return {48, 5, n, 'm'}; }
            constexpr auto set(const color_t r, const color_t g, const color_t b) -> csi<5> { return {48, 2, r, g, b, 'm'}; }
        }

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

        template <std::size_t N>
        constexpr auto operator<<(std::ostream& stream, const csi<N>& in) -> std::ostream&
        {
            if (&stream == &std::cout)
            {
                stream << "\x1b[" << static_cast<unsigned>(in.value[0]);

                for (std::size_t i = 1; i < N; i++)
                    stream << ";" << static_cast<unsigned>(in.value[i]);

                stream << in.type;
            }

            return stream;
        }

#pragma region Stream Operator Optimization
        template <>
        constexpr auto operator<<(std::ostream& stream, const csi<1>& in) -> std::ostream&
        {
            if (&stream == &std::cout)
                stream << "\x1b[" << static_cast<unsigned>(in.value[0]) << in.type;

            return stream;
        }

        template <>
        constexpr auto operator<<(std::ostream& stream, const csi<2>& in) -> std::ostream&
        {
            if (&stream == &std::cout)
                stream << "\x1b[" << static_cast<unsigned>(in.value[0]) << ";" << static_cast<unsigned>(in.value[1]) << in.type;

            return stream;
        }

        template <>
        constexpr auto operator<<(std::ostream& stream, const color8_t& in) -> std::ostream&
        {
            if (&stream == &std::cout)
                stream << "\x1b[" << static_cast<unsigned>(in.value[0]) << ";" << static_cast<unsigned>(in.value[1]) << ";" << static_cast<unsigned>(in.value[2]) << in.
                    type;

            return stream;
        }

        template <>
        constexpr auto operator<<(std::ostream& stream, const color24_t& in) -> std::ostream&
        {
            if (&stream == &std::cout)
                stream << "\x1b[" << static_cast<unsigned>(in.value[0]) << ";" << static_cast<unsigned>(in.value[1]) << ";" << static_cast<unsigned>(in.value[2]) << ";"
                    << static_cast<
                        int>(in.value[3]) << ";" << static_cast<unsigned>(in.value[4]) << in.
                    type;

            return stream;
        }
#pragma endregion
    }
}
