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

TEST(aoc2019, problem_03_part_2) {
    std::string input = "R75,D30,R83,U83,L12,D49,R71,U7,L72\nU62,R66,U55,R34,D71,R55,D58,R83";
    ASSERT_EQ(610, part2(input));

    input = "R98,U47,R26,D63,R33,U87,L62,D20,R33,U53,R51\nU98,R91,D20,R16,D67,R40,U7,R15,U6,R7";
    ASSERT_EQ(410, part2(input));
}