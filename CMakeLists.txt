cmake_minimum_required(VERSION 3.16)

project(hwod LANGUAGES CXX)

add_executable(hwod src/main.cpp)
add_executable(hj101_last_word src/hj101_last_word.cpp)
target_compile_features(hwod PRIVATE cxx_std_17)
target_compile_features(hj101_last_word PRIVATE cxx_std_17)
set_target_properties(hwod last_word PROPERTIES CXX_EXTENSIONS OFF)

if(MSVC)
    target_compile_options(hwod PRIVATE /utf-8)
    target_compile_options(hj101_last_word PRIVATE /utf-8)
endif()
