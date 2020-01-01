include(CTest)

macro(add_test_problem problem_sources year)
    foreach(problem ${ARGN})
        list(APPEND ${problem_sources}
                src/${year}/problem_${problem}.cpp)
    endforeach(problem)
    source_group(${year} src/${year}/*)
endmacro()

set(AOC_TEST_SOURCES)
add_test_problem(AOC_TEST_SOURCES 2019 01 02 03)

add_executable(aoctest ${AOC_TEST_SOURCES} src/main.cpp)
target_link_libraries(aoctest aocproblems gtest_main)

add_test(NAME aoctest COMMAND aoctest)