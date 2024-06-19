export module ansi:line;

import :csi;

export namespace ansi
{
    inline namespace manipulators
    {
        namespace line
        {
            constexpr auto next(const value_t n = 1) -> csi<1> { return {n, 'E'}; }
            constexpr auto prev(const value_t n = 1) -> csi<1> { return {n, 'F'}; }
        }
    }
}
