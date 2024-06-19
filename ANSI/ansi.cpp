#include "ansi.hpp"

#if __cplusplus >= 202002L
auto ansi::csi::caret::up(const color_t n) -> std::string { return std::format("\x1b[{}A", n); }
auto ansi::csi::caret::down(const color_t n) -> std::string { return std::format("\x1b[{}B", n); }
auto ansi::csi::caret::forward(const color_t n) -> std::string { return std::format("\x1b[{}C", n); }
auto ansi::csi::caret::back(const color_t n) -> std::string { return std::format("\x1b[{}D", n); }

auto ansi::csi::caret::move(const color_t n) -> std::string { return std::format("\x1b[{}G", n); }
auto ansi::csi::caret::move(const color_t n, const color_t m) -> std::string { return std::format("\x1b[{};{}H", n, m); }

auto ansi::csi::line::next(const color_t n) -> std::string { return std::format("\x1b[{}E", n); }
auto ansi::csi::line::prev(const color_t n) -> std::string { return std::format("\x1b[{}F", n); }

auto ansi::csi::erase::all(const color_t n) -> std::string { return std::format("\x1b[{}J", n); }
auto ansi::csi::erase::line(const color_t n) -> std::string { return std::format("\x1b[{}K", n); }

auto ansi::csi::scroll::up(const color_t n) -> std::string { return std::format("\x1b[{}S", n); }
auto ansi::csi::scroll::down(const color_t n) -> std::string { return std::format("\x1b[{}T", n); }

auto ansi::sgr::fg::set(const color_t n) -> std::string { return std::format("\x1b[38;5;{}m", n); }
auto ansi::sgr::fg::set(const color_t r, const color_t g, const color_t b) -> std::string { return std::format("\x1b[38;2;{};{};{}m", r, g, b); }

auto ansi::sgr::bg::set(const color_t n) -> std::string { return std::format("\x1b[48;5;{}m", n); }
auto ansi::sgr::bg::set(const color_t r, const color_t g, const color_t b) -> std::string { return std::format("\x1b[48;2;{};{};{}m", r, g, b); }
#endif
