cmake_minimum_required(VERSION 3.13.0 FATAL_ERROR)

project(mtg_deck_builder VERSION 0.1.0 LANGUAGES CXX)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR
   CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_options(-g -Wall -Wextra -Werror -fPIC -pedantic)
endif()

find_package(nlohmann_json)

add_subdirectory(src)
