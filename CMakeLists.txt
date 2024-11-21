cmake_minimum_required(VERSION 3.22)

project(mtg_deck_builder)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR
   CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_options(-g -Wall -Wextra -Werror -fPIC -pedantic)
endif()

find_package(nlohmann_json)
find_package(JUCE CONFIG REQUIRED)

add_subdirectory(src)
