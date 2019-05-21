#include "cardFromJson.h"

void mtg_card::to_json(nlohmann::json& j, const mtg_card::Card& c) {
    //TODO
    j = nlohmann::json{{"name", c.name}, {"colors", c.colors}};
}

void mtg_card::from_json(const nlohmann::json& j, mtg_card::Card& c) {
    j.at("name").get_to(c.name);
    j.at("convertedManaCost").get_to(c.convertedManaCost);
    if(j.contains("manaCost"))
        c.manaCost = j.at("manaCost").get<std::string>();

    for(auto& color : j.at("colors"))
    {
        //TODO
        c.colors.emplace_back(color.get<std::string>());
    }
}
