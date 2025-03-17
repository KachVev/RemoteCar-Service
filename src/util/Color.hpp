#pragma once

using u_char = unsigned char;

struct Color {
    u_char r, g, b;

    Color(const u_char r, const u_char g, const u_char b) : r(r), g(g), b(b) {}
};

