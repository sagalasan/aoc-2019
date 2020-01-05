#include "gtest/gtest.h"
#include "2019/problem_04.h"

using namespace aoc::year_2019::day04;

TEST(aoc2019, problem_04_is_valid_pass) {
    ASSERT_TRUE(is_valid_pass("111111"));
    ASSERT_FALSE(is_valid_pass("223450"));
    ASSERT_FALSE(is_valid_pass("123789"));
}

TEST(aoc2019, problem_04_is_valid_pass2) {
    ASSERT_TRUE(is_valid_pass2("112233"));
    ASSERT_FALSE(is_valid_pass2("123444"));
    ASSERT_TRUE(is_valid_pass2("111122"));
}