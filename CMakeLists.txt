cmake_minimum_required(VERSION 3.11)
project(aoc_2019 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(aoc)

add_executable(aoc2019 aoc/src/main.cpp)
target_link_libraries(aoc2019 aocproblems)
