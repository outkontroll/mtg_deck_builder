#ifndef CARDFROMJSON_H
#define CARDFROMJSON_H

#include <nlohmann/json.hpp>

namespace mtg_card {

struct Card;
enum class Type;
enum class Color;

void to_json(nlohmann::json& j, const Card& c);
void from_json(const nlohmann::json& j, Card& c);

void to_json(nlohmann::json& j, Type t);
void from_json(const nlohmann::json& j, Type& t);

void to_json(nlohmann::json& j, Color c);
void from_json(const nlohmann::json& j, Color& c);

}

#endif // CARDFROMJSON_H
