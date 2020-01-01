#include "gtest/gtest.h"
#include "2019/problem_03.h"

using namespace aoc::year_2019::day03;

TEST(aoc2019, problem_03_manhattan_distance) {
    ASSERT_EQ(6, manhattan_distance(0, 0, 3, 3));
    ASSERT_EQ(6, manhattan_distance(3, 3, 0, 0));
    ASSERT_EQ(8, manhattan_distance(3, 4, -1, 0));
}

TEST(aoc2019, problem_03_parse_input) {
    std::vector<std::vector<PathInstruction>> expected = {{
        PathInstruction {Direction::RIGHT, 8},
        PathInstruction {Direction::UP, 5},
        PathInstruction {Direction::LEFT, 5},
        PathInstruction {Direction::DOWN, 3},
    }};
    ASSERT_EQ(expected, parse_input("R8,U5,L5,D3"));
}

TEST(aoc2019, problem_03_part_1) {
    std::string input = "R8,U5,L5,D3\nU7,R6,D4,L4";

    ASSERT_EQ(6, part1(input));
}