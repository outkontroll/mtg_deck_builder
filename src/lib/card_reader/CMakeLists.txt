cmake_minimum_required(VERSION 3.13.0 FATAL_ERROR)

project(card_reader)

add_library(${PROJECT_NAME} STATIC card_reader.cpp card_reader.h cardFromJson.cpp cardFromJson.h)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC mtg_card::mtg_card)
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 20)
