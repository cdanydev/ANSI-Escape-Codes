export module ansi:scroll;

import :csi;

export namespace ansi
{
    inline namespace manipulators
    {
        namespace scroll
        {
            constexpr auto up(const value_t n = 1) -> csi<1> { return {n, 'S'}; }
            constexpr auto down(const value_t n = 1) -> csi<1> { return {n, 'T'}; }
        }
    }
}
