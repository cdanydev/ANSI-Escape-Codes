export module ansi:manip;

import std;

export namespace ansi
{
    using value_t = std::uint8_t;

    template <std::size_t N>
    struct manip final
    {
        value_t value[N];
        char type = 'm';
    };
    
    using control_t = manip<1>;
    using style_t = manip<1>;
    using color4_t = manip<1>;
    using color8_t = manip<3>;
    using color24_t = manip<5>;
}
