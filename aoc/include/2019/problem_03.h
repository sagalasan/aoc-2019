#ifndef AOC_2019_PROBLEM_03_H
#define AOC_2019_PROBLEM_03_H

#include <cstddef>
#include <string>

namespace aoc::year_2019::day03 {
    enum class Direction {
        UP, DOWN, RIGHT, LEFT
    };

    struct PathInstruction {
        Direction direction;
        std::uint64_t distance;

        bool operator==(const PathInstruction& rhs) const {
            return this->direction == rhs.direction
            && this->distance == rhs.distance;
        }
    };

    template <class InputIt, class OutputIt>
    void evaluate_path(const std::vector<PathInstruction>& instructions, Container& container) {
//    void evaluate_path(InputIt first, InputIt last, OutputIt d_first) {
        auto begin = instructions.begin();

        std::int64_t x = 0;
        std::int64_t y = 0;

        for (const auto& instruction : instructions) {
            std::int64_t x_inc = 0;
            std::int64_t y_inc = 0;
            switch (instruction.direction) {
                case Direction::UP:
                    y_inc = 1;
                    break;
                case Direction::DOWN:
                    y_inc = -1;
                    break;
                case Direction::RIGHT:
                    x_inc = 1;
                    break;
                case Direction::LEFT:
                    x_inc = -1;
                    break;
            }

            for (std::uint64_t i = 0; i < instruction.distance; ++i) {
                x += x_inc;
                y += y_inc;

                container.insert()
            }
        }
    }

    std::int64_t manhattan_distance(std::int64_t x1, std::int64_t y1, std::int64_t x2, std::int64_t y2);

    std::vector<std::vector<PathInstruction>> parse_input(const std::string& input);
    std::size_t part1(const std::string& input);
    std::size_t part2(const std::string& input);
}

#endif //AOC_2019_PROBLEM_03_H
