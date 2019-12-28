#include "gtest/gtest.h"
#include "2019/problem_01.h"

TEST(aoc2019, problem_01_1)
{
    ASSERT_EQ(2, aoc::year_2019::day01_part1("12"));
    ASSERT_EQ(2, aoc::year_2019::day01_part1("14"));
    ASSERT_EQ(654, aoc::year_2019::day01_part1("1969"));
    ASSERT_EQ(33583, aoc::year_2019::day01_part1("100756"));
}

TEST(aoc2019, problem_01_2)
{
    ASSERT_EQ(2, aoc::year_2019::day01_part2("12"));
    ASSERT_EQ(2, aoc::year_2019::day01_part2("14"));
    ASSERT_EQ(966, aoc::year_2019::day01_part2("1969"));
    ASSERT_EQ(50346, aoc::year_2019::day01_part2("100756"));
}