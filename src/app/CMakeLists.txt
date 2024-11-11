cmake_minimum_required(VERSION 3.13.0 FATAL_ERROR)

project(mtg_deck_builder)

add_executable(${PROJECT_NAME} main.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

target_link_libraries(${PROJECT_NAME} PUBLIC card_reader::card_reader mtg_card::mtg_card)
