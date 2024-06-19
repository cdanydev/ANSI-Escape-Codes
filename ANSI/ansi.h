#pragma once

#define ESC "\x1b["

#if __STDC_VERSION__ == 202311L
// C23 constexpr alternatives to the macros.
#endif

#if defined(ANSI_USE_MACROS) || __STDC_VERSION__ < 202311L
#define CUU(n) ESC #n "A"
#define CUD(n) ESC #n "B"
#define CUF(n) ESC #n "C"
#define CUB(n) ESC #n "D"
#define CNL(n) ESC #n "E"
#define CPL(n) ESC #n "F"
#define CHA(n) ESC #n "G"
#define CUP(n, m) ESC #n ";" #m "H"
#define ED(n) ESC #n "J"
#define EL(n) ESC #n "K"
#define SU(n) ESC #n "S"
#define SD(n) ESC #n "T"
#define HVP(n, m) ESC #n ";" #m "f"
#define SGR(n) ESC #n "m"

#define RESET SGR(0)
#define BOLD SGR(1)
#define FAINT SGR(2)
#define ITALIC SGR(3)
#define UNDERLINE SGR(4)
#define BLINK SGR(5)
#define INVERT SGR(7)
#define HIDE SGR(8)
#define STRIKE SGR(9)
#define DOUBLE_UNDERLINE SGR(21)
#define OVERLINE SGR(53)

#define NO_BOLD SGR(22)
#define NO_FAINT SGR(22)
#define NO_ITALIC SGR(23)
#define NO_UNDERLINE SGR(24)
#define NO_BLINK SGR(25)
#define NO_INVERT SGR(27)
#define REVERT NO_INVERT
#define NO_HIDE SGR(28)
#define NO_STRIKE SGR(29)
#define REVEAL NO_HIDE
#define NO_OVERLINE SGR(55)

#define FG_BLACK SGR(30)
#define FG_RED SGR(31)
#define FG_GREEN SGR(32)
#define FG_YELLOW SGR(33)
#define FG_INDIGO SGR(34)
#define FG_MAGENTA SGR(35)
#define FG_CYAN SGR(36)
#define FG_WHITE SGR(37)
#define FG_GRAY SGR(90)

#define FG_BRIGHT_BLACK SGR(90)
#define FG_BRIGHT_RED SGR(91)
#define FG_BRIGHT_GREEN SGR(92)
#define FG_BRIGHT_YELLOW SGR(93)
#define FG_BRIGHT_INDIGO SGR(94)
#define FG_BRIGHT_MAGENTA SGR(95)
#define FG_BRIGHT_CYAN SGR(96)
#define FG_BRIGHT_WHITE SGR(97)

#define FG(n) SGR(38;5;n)
#define FG_RGB(r, g, b) SGR(38;2;r;g;b)

#define BG_BLACK SGR(40)
#define BG_RED SGR(41)
#define BG_GREEN SGR(42)
#define BG_YELLOW SGR(43)
#define BG_INDIGO SGR(44)
#define BG_MAGENTA SGR(45)
#define BG_CYAN SGR(46)
#define BG_WHITE SGR(47)
#define BG_GRAY SGR(100)

#define BG_BRIGHT_BLACK SGR(100)
#define BG_BRIGHT_RED SGR(101)
#define BG_BRIGHT_GREEN SGR(102)
#define BG_BRIGHT_YELLOW SGR(103)
#define BG_BRIGHT_INDIGO SGR(104)
#define BG_BRIGHT_MAGENTA SGR(105)
#define BG_BRIGHT_CYAN SGR(106)
#define BG_BRIGHT_WHITE SGR(107)

#define FG(n) SGR(48;5;n)
#define FG_RGB(r, g, b) SGR(48;2;r;g;b)
#endif
