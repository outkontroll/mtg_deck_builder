cmake_minimum_required(VERSION 3.13.0 FATAL_ERROR)

project(card_reader)

add_library(${PROJECT_NAME} STATIC card_reader.cpp card_reader.h)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE mtg_card::mtg_card)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)
