add_subdirectory(thirdparty)

macro(add_problem problem_sources year)
    foreach(problem ${ARGN})
        list(APPEND ${problem_sources}
                include/${year}/problem_${problem}.h
                src/${year}/problem_${problem}.cpp)
    endforeach(problem)
    source_group(${year} include/${year}/*|src/${year}/*)
endmacro()

set(AOC_SOURCES include/problem.h src/problem.cpp
        include/util.h
        include/2019/intcode.h src/2019/intcode.cpp
        )

add_problem(AOC_SOURCES 2019 01 02 03 04 05)

file(GLOB AOC_RESOURCES resources/*.txt)
file(COPY ${AOC_RESOURCES} DESTINATION "resources")

add_library(aocproblems ${AOC_SOURCES})
target_include_directories(aocproblems PUBLIC include)

target_link_libraries(aocproblems ${Boost_LIBRARIES})