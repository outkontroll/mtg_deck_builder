#ifndef CARD_H
#define CARD_H

#include <string>
#include <vector>
#include <optional>
#include "types.h"
#include "colors.h"

namespace mtg_card {

struct Card
{
    std::vector<Color> colors;
    std::vector<Type> types;
    std::vector<std::string> subtypes;
    std::vector<std::string> supertypes;
    std::optional<std::string> manaCost;
    std::string name;
    std::string text;
    int convertedManaCost = 0;
};

}

#endif // CARD_H
