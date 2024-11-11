#include "cardFromJson.h"
#include "card.h"

using json = nlohmann::json;

void mtg_card::to_json(json& /*j*/, const mtg_card::Card& /*c*/)
{
}

void mtg_card::from_json(const json& j, mtg_card::Card& c)
{
    j.at("name").get_to(c.name);
    j.at("convertedManaCost").get_to(c.convertedManaCost);

    if(j.contains("text"))
    {
        j.at("text").get_to(c.text);
    }

    if(j.contains("manaCost"))
    {
        c.manaCost = j.at("manaCost").get<std::string>();
    }

    for(const auto& color : j.at("colors"))
    {
        c.colors.emplace_back(color.get<mtg_card::Color>());
    }

    for(const auto& type : j.at("types"))
    {
        c.types.emplace_back(type.get<mtg_card::Type>());
    }

    for(const auto& subtype : j.at("subtypes"))
    {
        c.subtypes.emplace_back(subtype.get<std::string>());
    }

    for(const auto& supertype : j.at("supertypes"))
    {
        c.supertypes.emplace_back(supertype.get<std::string>());
    }
}

void mtg_card::to_json(json& /*j*/, mtg_card::Type /*t*/)
{
}

void mtg_card::from_json(const json& j, mtg_card::Type& t)
{
    if(!j.is_string())
    {
        throw std::runtime_error("unknown type of json");
    }

    const auto typeString = j.get<std::string>();
    const auto type = to_type(typeString);
    if(!type.has_value())
        throw std::runtime_error("unknown card type: " + typeString);

    t = *type;
}

void mtg_card::to_json(json& /*j*/, mtg_card::Color /*c*/)
{
}

void mtg_card::from_json(const json& j, mtg_card::Color& c)
{
    if(!j.is_string())
    {
        throw std::runtime_error("unknown type of json");
    }

    const auto colorString = j.get<std::string>();
    const auto color = to_color(colorString);
    if(!color.has_value())
        throw std::runtime_error("unknown card colod: " + colorString);

    c = *color;
}
