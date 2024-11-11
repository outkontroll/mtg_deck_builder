cmake_minimum_required(VERSION 3.10.0 FATAL_ERROR)

project(mtg_card)

set(HEADER_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/card.h
    ${CMAKE_CURRENT_SOURCE_DIR}/colors.h
    ${CMAKE_CURRENT_SOURCE_DIR}/types.h
)

add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

#target_sources(${PROJECT_NAME} INTERFACE ${HEADER_SOURCES})
if(WIN32)
  source_group(include FILES ${HEADER_SOURCES})
endif()

target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_17)

# hack to show the files in the IDE
add_custom_target(${PROJECT_NAME}_IDE SOURCES ${HEADER_SOURCES})

