cmake_minimum_required(VERSION 3.28)
project(Algorithm)

set(CMAKE_CXX_STANDARD 17)

add_executable(Algorithm main.cpp)

add_executable(solving_21940 solving/21940.cpp)
add_executable(solving_1956 solving/1956.cpp)
add_executable(SCC solving/2150.cpp)