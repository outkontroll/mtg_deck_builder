cmake_minimum_required(VERSION 3.10.0 FATAL_ERROR)

project(mtg_deck_builder VERSION 0.1.0 LANGUAGES CXX)

add_executable(${PROJECT_NAME} main.cpp)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
