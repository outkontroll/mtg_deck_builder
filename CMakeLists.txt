cmake_minimum_required(VERSION 3.10.0 FATAL_ERROR)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR
   CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_options(-g -Wall -Wextra -Werror -fPIC -pedantic)
endif()

add_subdirectory(src)
