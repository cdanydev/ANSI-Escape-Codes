export module ansi:erase;

import :csi;

export namespace ansi
{
    inline namespace manipulators
    {
        namespace erase
        {
            enum erase_mode final : value_t { from_caret, to_caret, whole };

            constexpr auto all(const erase_mode n = whole) -> csi<1> { return {n, 'J'}; }
            constexpr auto line(const erase_mode n = whole) -> csi<1> { return {n, 'K'}; }
        }
    }
}
