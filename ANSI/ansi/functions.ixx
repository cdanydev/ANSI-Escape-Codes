export module ansi:functions;

import std;
import ansi.manip;
import :modifiers;

export namespace ansi
{
    namespace caret
    {
        constexpr auto up(std::ostream& stream, const std::uint8_t n = 1) -> void { stream << manipulators::caret::up(n); }
        constexpr auto up(const std::uint8_t n = 1) -> void { up(std::cout, n); }

        constexpr auto down(std::ostream& stream, const std::uint8_t n = 1) -> void { stream << manipulators::caret::down(n); }
        constexpr auto down(const std::uint8_t n = 1) -> void { down(std::cout, n); }

        constexpr auto forward(std::ostream& stream, const std::uint8_t n = 1) -> void { stream << manipulators::caret::forward(n); }
        constexpr auto forward(const std::uint8_t n = 1) -> void { forward(std::cout, n); }

        constexpr auto back(std::ostream& stream, const std::uint8_t n = 1) -> void { stream << manipulators::caret::back(n); }
        constexpr auto back(const std::uint8_t n = 1) -> void { back(std::cout, n); }

        constexpr auto move(std::ostream& stream, const std::uint8_t row) -> void { stream << manipulators::caret::move(row); }
        constexpr auto move(const std::uint8_t row) -> void { up(std::cout, row); }

        constexpr auto move(std::ostream& stream, const std::uint8_t row, const std::uint8_t column) -> void { stream << manipulators::caret::move(row, column); }
        constexpr auto move(const std::uint8_t row, const std::uint8_t column) -> void { move(std::cout, row, column); }
    }

    namespace line
    {
        constexpr auto next(std::ostream& stream, const std::uint8_t n = 1) -> void { stream << manipulators::line::next(n); }
        constexpr auto next(const std::uint8_t n = 1) -> void { next(std::cout, n); }
        
        constexpr auto prev(std::ostream& stream, const std::uint8_t n = 1) -> void { stream << manipulators::line::prev(n); }
        constexpr auto prev(const std::uint8_t n = 1) -> void { prev(std::cout, n); }
    }
    
    namespace erase
    {
        enum erase_mode final : std::uint8_t { from_caret, to_caret, whole };
    
        constexpr auto all(std::ostream& stream, const erase_mode n = whole) -> void { stream << manipulators::erase::all(static_cast<manipulators::erase::erase_mode>(n)); }
        constexpr auto all(const erase_mode n = whole) -> void { all(std::cout, n); }
        
        constexpr auto line(std::ostream& stream, const erase_mode n = whole) -> void { stream << manipulators::erase::line(static_cast<manipulators::erase::erase_mode>(n)); }
        constexpr auto line(const erase_mode n = whole) -> void { line(std::cout, n); }
    }
    
    namespace scroll
    {
        constexpr auto up(std::ostream& stream, const std::uint8_t n = 1) -> void { stream << manipulators::scroll::up(n); }
        constexpr auto up(const std::uint8_t n = 1) -> void { up(std::cout, n); }
        
        constexpr auto down(std::ostream& stream, const std::uint8_t n = 1) -> void { stream << manipulators::scroll::down(n); }
        constexpr auto down(const std::uint8_t n = 1) -> void { down(std::cout, n); }
    }

    template <style... Modifiers, typename... Args>
    auto print(std::ostream& stream, const std::format_string<Args...> fmt, Args&&... args) -> void
    {
        if constexpr (sizeof...(Modifiers) > 0)
        {
            stream << "\x1b[";
            (..., (stream << ';' << Modifiers)) << 'm';

            std::vprint_unicode(fmt.get(), std::make_format_args(args...));
            stream << "\x1b[0m";
        }
        else std::vprint_unicode(fmt.get(), std::make_format_args(args...));
    }

    template <style... Modifiers, typename... Args>
    auto print(const std::format_string<Args...> fmt, Args&&... args) -> void
    {
        ansi::print<Modifiers...>(std::cout, fmt, std::forward<Args>(args)...);
    }

    template <style... Modifiers, typename... Args>
    auto println(std::ostream& stream, const std::format_string<Args...> fmt, Args&&... args) -> void
    {
        ansi::print<Modifiers...>(stream, fmt, std::forward<Args>(args)...);
        stream << std::endl;
    }

    template <style... Modifiers, typename... Args>
    auto println(const std::format_string<Args...> fmt, Args&&... args) -> void
    {
        ansi::println<Modifiers...>(std::cout, fmt, std::forward<Args>(args)...);
    }
}
