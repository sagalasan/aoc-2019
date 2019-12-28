cmake_minimum_required(VERSION 3.10)
project(aoc_2019 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(aoc)

add_executable(aoc2019 aoc/src/main.cpp)
target_link_libraries(aoc2019 aocproblems)

#set(SOURCES
#        aoc/include/problem.h
#        aoc/src/problem.cpp)



#add_executable(aoc_2019 main.cpp)
#add_executable(problem1 aoc/problem1.cpp)
#add_executable(problem2 aoc/problem2.cpp)
#add_executable(problem3 aoc/problem3.cpp)