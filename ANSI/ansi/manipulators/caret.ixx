export module ansi:caret;

import :csi;

export namespace ansi
{
    inline namespace manipulators
    {
        namespace caret
        {
            constexpr auto up(const value_t n = 1) -> csi<1> { return {n, 'A'}; }
            constexpr auto down(const value_t n = 1) -> csi<1> { return {n, 'B'}; }
            constexpr auto forward(const value_t n = 1) -> csi<1> { return {n, 'C'}; }
            constexpr auto back(const value_t n = 1) -> csi<1> { return {n, 'D'}; }
            constexpr auto move(const value_t row) -> csi<1> { return {row, 'G'}; }
            constexpr auto move(const value_t row, const value_t column) -> csi<2> { return {row, column, 'H'}; }
        }
    }
}
