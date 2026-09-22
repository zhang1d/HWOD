cmake_minimum_required(VERSION 3.16)

project(hwod LANGUAGES CXX)

add_executable(hwod src/main.cpp)
target_compile_features(hwod PRIVATE cxx_std_17)
set_target_properties(hwod PROPERTIES CXX_EXTENSIONS OFF)

if(MSVC)
    target_compile_options(hwod PRIVATE /utf-8)
endif()
