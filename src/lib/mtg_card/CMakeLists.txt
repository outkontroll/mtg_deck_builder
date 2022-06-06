cmake_minimum_required(VERSION 3.10.0 FATAL_ERROR)

project(mtg_card)

add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} INTERFACE ${PROJECT_SOURCE_DIR})
target_sources(${PROJECT_NAME} INTERFACE ${PROJECT_SOURCE_DIR}/card.h ${PROJECT_SOURCE_DIR}/colors.h)
source_group(include FILES ${PROJECT_SOURCE_DIR}/card.h ${PROJECT_SOURCE_DIR}/colors.h)
