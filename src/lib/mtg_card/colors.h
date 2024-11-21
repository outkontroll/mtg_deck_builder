#ifndef COLORS_H
#define COLORS_H

#include <string_view>
#include <optional>
#include <vector>
#include <numeric>
#include <string>

namespace mtg_card {

enum class Color {
    White,
    Blue,
    Black,
    Red,
    Green
};

inline constexpr auto to_string(Color color)
{
    switch (color)
    {
    case Color::White:
        return "W";
    case Color::Blue:
        return "U";
    case Color::Black:
        return "B";
    case Color::Red:
        return "R";
    case Color::Green:
        return "G";
    }
    return "";
}

inline auto to_string(const std::vector<Color>& colors) -> std::string
{
    if(colors.empty())
        return "Colorless";

    return std::accumulate(colors.begin(), colors.end(), std::string{}, [&](std::string s, Color color){
        return std::move(s) + to_string(color);
    });
}

inline constexpr std::optional<Color> to_color(std::string_view color)
{
    if(color == "W")
        return Color::White;
    else if(color == "U")
        return Color::Blue;
    else if(color == "B")
        return Color::Black;
    else if(color == "R")
        return Color::Red;
    else if(color == "G")
        return Color::Green;

    return std::nullopt;
}

}

#endif //COLORS_H
