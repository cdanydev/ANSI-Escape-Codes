export module ansi:functions;

import std;
import :manipulators;
import :manip;

export namespace ansi
{
    template <std::size_t N>
    constexpr auto operator<<(std::ostream& stream, const manip<N>& in) -> std::ostream&
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
    constexpr auto operator<<(std::ostream& stream, const manip<1>& in) -> std::ostream&
    {
        if (&stream == &std::cout)
            stream << "\x1b[" << static_cast<unsigned>(in.value[0]) << in.type;

        return stream;
    }

    template <>
    constexpr auto operator<<(std::ostream& stream, const manip<2>& in) -> std::ostream&
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
            stream << "\x1b[" << static_cast<unsigned>(in.value[0]) << ";" << static_cast<unsigned>(in.value[1]) << ";" << static_cast<unsigned>(in.value[2]) << ";"
                << static_cast<int>(in.value[3]) << ";" << static_cast<unsigned>(in.value[4]) << in.type;

        return stream;
    }

#pragma endregion

    namespace caret
    {
        constexpr auto up(std::ostream& stream, const value_t n = 1) -> void { stream << manipulators::caret::up(n); }
        constexpr auto up(const value_t n = 1) -> void { up(std::cout, n); }

        constexpr auto down(std::ostream& stream, const value_t n = 1) -> void { stream << manipulators::caret::down(n); }
        constexpr auto down(const value_t n = 1) -> void { down(std::cout, n); }

        constexpr auto forward(std::ostream& stream, const value_t n = 1) -> void { stream << manipulators::caret::forward(n); }
        constexpr auto forward(const value_t n = 1) -> void { forward(std::cout, n); }

        constexpr auto back(std::ostream& stream, const value_t n = 1) -> void { stream << manipulators::caret::back(n); }
        constexpr auto back(const value_t n = 1) -> void { back(std::cout, n); }

        constexpr auto move(std::ostream& stream, const value_t row) -> void { stream << manipulators::caret::move(row); }
        constexpr auto move(const value_t row) -> void { up(std::cout, row); }

        constexpr auto move(std::ostream& stream, const value_t row, const value_t column) -> void { stream << manipulators::caret::move(row, column); }
        constexpr auto move(const value_t row, const value_t column) -> void { move(std::cout, row, column); }
    }

    namespace line
    {
        constexpr auto next(std::ostream& stream, const value_t n = 1) -> void { stream << manipulators::line::next(n); }
        constexpr auto next(const value_t n = 1) -> void { next(std::cout, n); }

        constexpr auto prev(std::ostream& stream, const value_t n = 1) -> void { stream << manipulators::line::prev(n); }
        constexpr auto prev(const value_t n = 1) -> void { prev(std::cout, n); }
    }

    namespace erase
    {
        enum erase_mode final : value_t { from_caret, to_caret, whole };

        constexpr auto all(std::ostream& stream, const erase_mode how = whole) -> void
        {
            stream << manipulators::erase::all(static_cast<manipulators::erase::erase_mode>(how));
        }

        constexpr auto all(const erase_mode how = whole) -> void { all(std::cout, how); }

        constexpr auto line(std::ostream& stream, const erase_mode how = whole) -> void
        {
            stream << manipulators::erase::line(static_cast<manipulators::erase::erase_mode>(how));
        }

        constexpr auto line(const erase_mode how = whole) -> void { line(std::cout, how); }
    }

    namespace scroll
    {
        constexpr auto up(std::ostream& stream, const value_t n = 1) -> void { stream << manipulators::scroll::up(n); }
        constexpr auto up(const value_t n = 1) -> void { up(std::cout, n); }

        constexpr auto down(std::ostream& stream, const value_t n = 1) -> void { stream << manipulators::scroll::down(n); }
        constexpr auto down(const value_t n = 1) -> void { down(std::cout, n); }
    }

    template <manip... Modifiers, typename... Args>
    auto print(std::ostream& stream, const std::string_view fmt, Args&&... args) -> void
    {
        if constexpr (sizeof...(Modifiers) > 0)
        {
            (..., (stream << Modifiers));

            std::vprint_unicode(stream, fmt, std::make_format_args(args...));
            stream << "\x1b[0m";
        }
        else std::vprint_unicode(stream, fmt, std::make_format_args(args...));
    }

    template <manip... Modifiers, typename... Args>
    auto print(const std::string_view fmt, Args&&... args) -> void
    {
        ansi::print<Modifiers...>(std::cout, fmt, std::forward<Args>(args)...);
    }

    template <manip... Modifiers, typename... Args>
    auto println(std::ostream& stream, const std::string_view fmt, Args&&... args) -> void
    {
        ansi::print<Modifiers...>(stream, fmt, std::forward<Args>(args)...);
        stream << std::endl;
    }

    template <manip... Modifiers, typename... Args>
    auto println(const std::string_view fmt, Args&&... args) -> void
    {
        ansi::println<Modifiers...>(std::cout, fmt, std::forward<Args>(args)...);
    }

    inline auto println(std::ostream& stream) -> void
    {
        stream << std::endl;
    }

    inline auto println() -> void
    {
        ansi::println(std::cout);
    }
}
