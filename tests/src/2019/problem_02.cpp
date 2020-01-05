#include "gtest/gtest.h"
#include "2019/intcode.h"
#include "2019/problem_02.h"

#include <utility>

std::uint64_t run_intcode(std::vector<int64_t> memory) {
    aoc::year_2019::Intcode intcode(std::move(memory));
    return intcode.run_program();
}

TEST(aoc2019, problem_02_parse_input) {
    ASSERT_EQ(std::vector<std::int64_t>({1,9,10,3,2,3,11,0,99,30,40,50}), aoc::year_2019::parse_intcode("1,9,10,3,2,3,11,0,99,30,40,50"));
}

TEST(aoc2019, problem_02_intcode) {
    ASSERT_EQ(3500, run_intcode({1,9,10,3,2,3,11,0,99,30,40,50}));
}