#ifndef CARDFROMJSON_H
#define CARDFROMJSON_H

#include <nlohmann/json.hpp>
#include "card.h"

namespace mtg_card {

    void to_json(nlohmann::json& j, const Card& c) {
        //TODO
        j = nlohmann::json{{"name", c.name}, {"colors", c.colors}};
    }

    void from_json(const nlohmann::json& j, Card& c) {
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

}

#endif // CARDFROMJSON_H
