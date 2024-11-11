#ifndef CARD_TYPES_H
#define CARD_TYPES_H

#include <string_view>
#include <optional>

namespace mtg_card {

enum class Type
{
    land,
    creature,
    artifact,
    enchantment,
    sorcery,
    instant,
    scheme,
    summon,
    plane,
    conspiracy,
    planeswalker,
    vanguard,
    tribal,
    eaturecray,
    hero,
    scariest,
    youll,
    ever,
    see,
    phenomenon,
};

inline constexpr auto to_string(Type type)
{
    switch (type)
    {
    case Type::land:
        return "Land";
    case Type::creature:
        return "Creature";
    case Type::artifact:
        return "Artifact";
    case Type::enchantment:
        return "Enchantment";
    case Type::sorcery:
        return "Sorcery";
    case Type::instant:
        return "Instant";
    case Type::scheme:
        return "Scheme";
    case Type::summon:
        return "Summon";
    case Type::plane:
        return "Plane";
    case Type::conspiracy:
        return "Conspiracy";
    case Type::planeswalker:
        return "Planeswalker";
    case Type::vanguard:
        return "Vanguard";
    case Type::tribal:
        return "Tribal";
    case Type::eaturecray:
        return "Eaturecray";
    case Type::hero:
        return "Hero";
    case Type::scariest:
        return "Scariest";
    case Type::youll:
        return "Youll";
    case Type::ever:
        return "Ever";
    case Type::see:
        return "See";
    case Type::phenomenon:
        return "Phenomenon";
    }
    return "";
}

inline constexpr std::optional<Type> to_type(std::string_view typeString)
{
    if(typeString == "Land")
        return Type::land;
    else if(typeString == "Creature")
        return Type::creature;
    else if(typeString == "Artifact")
        return Type::artifact;
    else if(typeString == "Enchantment")
        return Type::enchantment;
    else if(typeString == "Instant" || typeString == "instant")
        return Type::instant;
    else if(typeString == "Sorcery")
        return Type::sorcery;
    else if(typeString == "Scheme")
        return Type::scheme;
    else if(typeString == "Summon")
        return Type::summon;
    else if(typeString == "Plane")
        return Type::plane;
    else if(typeString == "Conspiracy")
        return Type::conspiracy;
    else if(typeString == "Planeswalker")
        return Type::planeswalker;
    else if(typeString == "Vanguard")
        return Type::vanguard;
    else if(typeString == "Tribal")
        return Type::tribal;
    else if(typeString == "Eaturecray")
        return Type::eaturecray;
    else if(typeString == "Hero")
        return Type::hero;
    else if(typeString == "Scariest")
        return Type::scariest;
    else if(typeString == "You’ll")
        return Type::youll;
    else if(typeString == "Ever")
        return Type::ever;
    else if(typeString == "See")
        return Type::see;
    else if(typeString == "Phenomenon")
        return Type::phenomenon;
    else
        return std::nullopt;
}

}

#endif //CARD_TYPES_H
