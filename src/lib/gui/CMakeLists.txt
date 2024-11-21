cmake_minimum_required(VERSION 3.22)

project(gui)

set(CPP_SOURCES
    mainwindow.cpp
    MainComponent.cpp
    mainmenu.cpp
)

set(CPP_HEADERS
    mainwindow.h
    MainComponent.h
    mainmenu.h
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
        # JUCE_WEB_BROWSER and JUCE_USE_CURL would be on by default, but you might not need them.
        JUCE_WEB_BROWSER=0  # If you remove this, add `NEEDS_WEB_BROWSER TRUE` to the `juce_add_gui_app` call
        JUCE_USE_CURL=0     # If you remove this, add `NEEDS_CURL TRUE` to the `juce_add_gui_app` call
#        JUCE_APPLICATION_NAME_STRING="$<TARGET_PROPERTY:GuiAppExample,JUCE_PRODUCT_NAME>"
#        JUCE_APPLICATION_VERSION_STRING="$<TARGET_PROPERTY:GuiAppExample,JUCE_VERSION>"
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        # GuiAppData            # If we'd created a binary data target, we'd link to it here
        juce::juce_gui_extra
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
