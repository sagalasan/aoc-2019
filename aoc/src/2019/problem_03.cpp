#include <problem.h>
#include <2019/problem_03.h>
#include <sstream>
#include <iostream>
#include <set>

using namespace aoc::year_2019::day03;

namespace {
    PathInstruction parse_instruction(const std::string& instruction) {
        if (instruction.size() < 2) {
            throw std::runtime_error("instruction must be at leas 2 characters");
        }

        Direction direction;
        switch (instruction[0]) {
            case 'U':
                direction = Direction::UP;
                break;
            case 'D':
                direction = Direction::DOWN;
                break;
            case 'R':
                direction = Direction::RIGHT;
                break;
            case 'L':
                direction = Direction::LEFT;
                break;
            default:
                throw std::runtime_error("Invalid direction " + std::to_string(instruction[0]));
        }

        std::uint64_t distance = std::stoll(instruction.substr(1));
        return PathInstruction {direction, distance};
    }

    std::vector<PathInstruction> parse_instructions(const std::string& instructions) {
        std::vector<PathInstruction> result;
        std::istringstream stream(instructions);

        std::string raw_value;
        while (std::getline(stream, raw_value, ',')) {
            result.push_back(parse_instruction(raw_value));
        }

        return result;
    }
}

namespace aoc::year_2019::day03 {
    std::int64_t manhattan_distance(std::int64_t x1, std::int64_t y1, std::int64_t x2, std::int64_t y2) {
        return std::abs(x1 - x2) + std::abs(y1 - y2);
    }

    std::vector<std::vector<PathInstruction>> parse_input(const std::string& input) {
        std::vector<std::vector<PathInstruction>> result;
        std::istringstream stream(input);

        std::string line;
        while (std::getline(stream, line)) {
            result.push_back(parse_instructions(line));
        }

        return result;
    }

    std::size_t part1(const std::string& input) {
        std::vector<std::vector<PathInstruction>> instructions = parse_input(input);
        std::vector<PathInstruction> first = instructions[0];
        std::vector<PathInstruction> second = instructions[1];

        std::set<std::pair<std::int64_t, std::int64_t>> seen;
        std::set<std::pair<std::int64_t, std::int64_t>> intersections;

        for (const auto& instruction : first) {

        }

        return 0;
    }

    std::size_t part2(const std::string& input) {
        return 0;
    }
}