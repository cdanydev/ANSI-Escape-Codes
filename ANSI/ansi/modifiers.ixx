export module ansi:modifiers;

import std;

namespace ansi
{
    struct style final
    {
        union
        {
            struct
            {
                unsigned char code;
                unsigned char mode;
            } bit4;

            struct
            {
                unsigned char fg;
                unsigned char mode;
                unsigned char code;
            } bit8;

            struct
            {
                unsigned char fg;
                unsigned char mode;
                unsigned char r;
                unsigned char g;
                unsigned char b;
            } bit24;
        };

        friend constexpr auto operator<<(std::ostream& os, const style& obj) -> std::ostream&
        {
            switch (obj.bit4.mode)
            {
            default:
                return os << static_cast<int>(obj.bit4.code);
            case 5:
                return os << static_cast<int>(obj.bit8.fg) << ';' << 5 << ';' << static_cast<int>(obj.bit8.code);
            case 2:
                return os << static_cast<int>(obj.bit24.fg) << ';' << 2 << ';' << static_cast<int>(obj.bit24.r) << ';' << static_cast<int>(obj.bit24.g) << ';' <<
                    static_cast<
                        int>(obj.bit24.b);
            }
        }
    };

    export inline namespace modifiers
    {
        constexpr style normal{};
        constexpr style bold{1};
        constexpr style faint{2};
        constexpr style italic{3};
        constexpr style underline{4};
        constexpr style blink{5};
        constexpr style invert{7};
        constexpr style revert{27};
        constexpr style hide{8};
        constexpr style reveal{28};
        constexpr style strike{9};
        constexpr style double_underline{21};
        constexpr style overline{53};

        namespace un
        {
            constexpr style bold{22};
            constexpr style faint{22};
            constexpr style italic{23};
            constexpr style underline{24};
            constexpr style blink{25};
            constexpr style invert{27};
            constexpr style hide{28};
            constexpr style strike{29};
            constexpr style overline{55};
        }

        namespace fg
        {
            constexpr style normal{39};

            constexpr style black{30};
            constexpr style red{31};
            constexpr style green{32};
            constexpr style yellow{33};
            constexpr style indigo{34};
            constexpr style magenta{35};
            constexpr style cyan{36};
            constexpr style white{37};
            constexpr style gray{90};

            consteval auto set(const unsigned char code) -> style
            {
                return {.bit8 = {38, 5, code}};
            }

            consteval auto rgb(const unsigned char r, const unsigned char g, const unsigned char b) -> style
            {
                return {.bit24 = {38, 2, r, g, b}};
            }

            namespace bright
            {
                constexpr style black{90};
                constexpr style red{91};
                constexpr style green{92};
                constexpr style yellow{93};
                constexpr style indigo{94};
                constexpr style magenta{95};
                constexpr style cyan{96};
                constexpr style white{97};
            }
        }

        namespace bg
        {
            constexpr style normal{49};

            constexpr style black{40};
            constexpr style red{41};
            constexpr style green{42};
            constexpr style yellow{43};
            constexpr style indigo{44};
            constexpr style magenta{45};
            constexpr style cyan{46};
            constexpr style white{47};
            constexpr style gray{100};

            consteval auto set(const unsigned char code) -> style
            {
                return {.bit8 = {48, 5, code}};
            }

            consteval auto rgb(const unsigned char r, const unsigned char g, const unsigned char b) -> style
            {
                return {.bit24 = {48, 2, r, g, b}};
            }

            namespace bright
            {
                constexpr style black{100};
                constexpr style red{101};
                constexpr style green{102};
                constexpr style yellow{103};
                constexpr style indigo{104};
                constexpr style magenta{105};
                constexpr style cyan{106};
                constexpr style white{107};
            }
        }
    }
}
