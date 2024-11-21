cmake_minimum_required(VERSION 3.13.0 FATAL_ERROR)

project(game)

set(CPP_HEADERS
    game.h
    phases.h
    player.h
    zones.h
)

set(CPP_SOURCES
    game.cpp
    phases.cpp
    player.cpp
    zones.cpp
)

add_library(${PROJECT_NAME} STATIC ${CPP_SOURCES} ${CPP_HEADERS})
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
    mtg_card::mtg_card
    #deck::deck
)

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 20)
