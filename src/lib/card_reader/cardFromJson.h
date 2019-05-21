#ifndef CARDFROMJSON_H
#define CARDFROMJSON_H

#include <nlohmann/json.hpp>
#include "card.h"

namespace mtg_card {

    void to_json(nlohmann::json& j, const Card& c);

    void from_json(const nlohmann::json& j, Card& c);

}

#endif // CARDFROMJSON_H
