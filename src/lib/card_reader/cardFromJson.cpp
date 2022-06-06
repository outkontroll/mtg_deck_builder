#include "cardFromJson.h"
#include "card.h"
#include <iostream>

void mtg_card::to_json(nlohmann::json& j, const mtg_card::Card& c)
{
    j = nlohmann::json{{"name", c.name}, {"colors", c.colors}};
}

void mtg_card::from_json(const nlohmann::json& j, mtg_card::Card& c)
{
    j.at("name").get_to(c.name);
    j.at("convertedManaCost").get_to(c.convertedManaCost);

    if(j.contains("manaCost"))
    {
        c.manaCost = j.at("manaCost").get<std::string>();
    }

    for(const auto& color : j.at("colors"))
    {
        c.colors.emplace_back(color.get<std::string>());
    }

    for(const auto& type : j.at("types"))
    {
        c.types.emplace_back(type.get<mtg_card::Type>());
    }
}

void mtg_card::to_json(nlohmann::json& /*j*/, const mtg_card::Type& /*c*/)
{
}

void mtg_card::from_json(const nlohmann::json& j, mtg_card::Type& c)
{
    if(!j.is_string())
    {
        throw std::runtime_error("unknown type of json");
    }

    const auto typeString = j.get<std::string>();
    const auto type = to_type(typeString);
    if(!type.has_value())
        throw std::runtime_error("unknown card type: " + typeString);

    c = *type;
}
