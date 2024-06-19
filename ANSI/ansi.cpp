#include "ansi.hpp"

#if __cplusplus >= 202002L
auto ansi::csi::caret::up(const value_t n) -> std::string { return std::format("\x1b[{}A", n); }
auto ansi::csi::caret::down(const value_t n) -> std::string { return std::format("\x1b[{}B", n); }
auto ansi::csi::caret::forward(const value_t n) -> std::string { return std::format("\x1b[{}C", n); }
auto ansi::csi::caret::back(const value_t n) -> std::string { return std::format("\x1b[{}D", n); }

auto ansi::csi::caret::move(const value_t n) -> std::string { return std::format("\x1b[{}G", n); }
auto ansi::csi::caret::move(const value_t n, const value_t m) -> std::string { return std::format("\x1b[{};{}H", n, m); }

auto ansi::csi::line::next(const value_t n) -> std::string { return std::format("\x1b[{}E", n); }
auto ansi::csi::line::prev(const value_t n) -> std::string { return std::format("\x1b[{}F", n); }

auto ansi::csi::erase::all(const value_t n) -> std::string { return std::format("\x1b[{}J", n); }
auto ansi::csi::erase::line(const value_t n) -> std::string { return std::format("\x1b[{}K", n); }

auto ansi::csi::scroll::up(const value_t n) -> std::string { return std::format("\x1b[{}S", n); }
auto ansi::csi::scroll::down(const value_t n) -> std::string { return std::format("\x1b[{}T", n); }

auto ansi::csi::sgr(const value_t n) -> std::string { return std::format("\x1b[{}m", n); }

auto ansi::sgr::fg::set(const value_t n) -> std::string { return std::format("\x1b[38;5;{}m", n); }
auto ansi::sgr::fg::set(const value_t r, const value_t g, const value_t b) -> std::string { return std::format("\x1b[38;2;{};{};{}m", r, g, b); }

auto ansi::sgr::bg::set(const value_t n) -> std::string { return std::format("\x1b[48;5;{}m", n); }
auto ansi::sgr::bg::set(const value_t r, const value_t g, const value_t b) -> std::string { return std::format("\x1b[48;2;{};{};{}m", r, g, b); }
#endif
