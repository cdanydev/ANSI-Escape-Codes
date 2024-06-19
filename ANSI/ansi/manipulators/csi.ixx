export module ansi:csi;

import std;

export namespace ansi
{
    using value_t = unsigned char;

    template <std::size_t N>
    struct csi final
    {
        value_t value[N];
        char type;
    };

    using style_t = csi<1>;
    using color4_t = csi<1>;
    using color8_t = csi<3>;
    using color24_t = csi<5>;


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
            stream << "\x1b[" << static_cast<unsigned>(in.value[0]) << ";" << static_cast<unsigned>(in.value[1]) << ";" << static_cast<unsigned>(in.value[2]) << in.type;

        return stream;
    }

    template <>
    constexpr auto operator<<(std::ostream& stream, const color24_t& in) -> std::ostream&
    {
        if (&stream == &std::cout)
            stream << "\x1b[" << static_cast<unsigned>(in.value[0]) << ";" << static_cast<unsigned>(in.value[1]) << ";" << static_cast<unsigned>(in.value[2]) << ";" <<
                static_cast<int>(in.value[3]) << ";" << static_cast<unsigned>(in.value[4]) << in.type;

        return stream;
    }
#pragma endregion
}
