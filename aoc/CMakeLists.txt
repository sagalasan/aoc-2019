macro(add_problem problem_sources year)
    foreach(problem ${ARGN})
        list(APPEND ${problem_sources}
                include/${year}/problem_${problem}.h
                src/${year}/problem_${problem}.cpp)
    endforeach(problem)
    source_group(${year} include/${year}/*|src/${year}/*)
endmacro()

set(AOC_SOURCES include/problem.h src/problem.cpp)

add_problem(AOC_SOURCES 2019 01)

add_library(aocproblems ${AOC_SOURCES})
target_include_directories(aocproblems PUBLIC include)