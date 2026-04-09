cmake_minimum_required(VERSION 4.2)
project(algorithms)

set(CMAKE_CXX_STANDARD 26)

add_executable(algorithms main.cpp
        src/search_algorithms.cpp
        header/search_algorithms.h
        header/dynamic_array.h
        src/dynamic_array.cpp)
