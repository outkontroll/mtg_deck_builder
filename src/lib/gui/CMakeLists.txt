cmake_minimum_required(VERSION 3.22)

project(gui)

set(CPP_SOURCES
    mainwindow.cpp
    MainComponent.cpp
    mainmenu.cpp
    newgamepanel.cpp
)

set(CPP_HEADERS
    mainwindow.h
    MainComponent.h
    mainmenu.h
    newgamepanel.h
)

add_library(${PROJECT_NAME} STATIC)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
target_sources(${PROJECT_NAME}
    PUBLIC
        ${CPP_HEADERS}
    PRIVATE
        ${CPP_SOURCES}
)

target_compile_definitions(${PROJECT_NAME}
    PRIVATE
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        juce::juce_gui_extra
        juce::juce_animation
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 20)
