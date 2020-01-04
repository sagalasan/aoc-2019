#include <problem.h>
#include <2019/problem_03.h>
#include <sstream>
#include <iostream>
#include <set>
#include <unordered_set>
#include <util.h>
#include <boost/functional/hash.hpp>

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

        std::unordered_set<std::pair<std::int64_t, std::int64_t>,
                boost::hash<std::pair<std::int64_t, std::int64_t>>> seen;
        std::vector<std::pair<std::int64_t, std::int64_t>> second_path;
        std::unordered_set<std::pair<std::int64_t, std::int64_t>,
                boost::hash<std::pair<std::int64_t, std::int64_t>>> intersections;

        // Evaluate the first path into a set
        evaluate_path(first, std::inserter(seen, seen.end()));

        // Evaluate the second into a vector
        evaluate_path(second, std::back_inserter(second_path));

        for (const auto& pair : second_path) {
            auto search = seen.find(pair);
            if (search != seen.end()) {
                intersections.insert(*search);
            }
        }

        if (intersections.empty()) {
            return 0;
        }

        std::int64_t closest_dist = std::numeric_limits<std::int64_t>::max();
        for (const auto& pair : intersections) {
            std::int64_t dist = manhattan_distance(0, 0, pair.first, pair.second);
            if (dist < closest_dist) {
                closest_dist = dist;
            }
        }

        return closest_dist;
    }

    std::size_t part2(const std::string& input) {
        std::vector<std::vector<PathInstruction>> instructions = parse_input(input);
        std::vector<PathInstruction> first = instructions[0];
        std::vector<PathInstruction> second = instructions[1];

        std::unordered_map<std::pair<std::int64_t, std::int64_t>, std::int64_t,
        boost::hash<std::pair<std::int64_t, std::int64_t>>> seen;

        std::vector<std::pair<std::int64_t, std::int64_t>> first_path;
        std::vector<std::pair<std::int64_t, std::int64_t>> second_path;

        std::unordered_map<std::pair<std::int64_t, std::int64_t>, std::int64_t,
                boost::hash<std::pair<std::int64_t, std::int64_t>>> intersections;

        evaluate_path(first, std::back_inserter(first_path));
        evaluate_path(second, std::back_inserter(second_path));

        aoc::index_map(first_path.begin(), first_path.end(), std::inserter(seen, seen.end()));

        for (std::size_t i = 0; i < second_path.size(); ++i) {
            const auto& pair = second_path[i];
            auto search = seen.find(pair);
            if (search != seen.end()) {
                intersections.emplace(search->first, search->second + i + 2);
            }
        }

        std::int64_t least_steps = std::numeric_limits<std::int64_t>::max();
        for (const auto& entry : intersections) {
            if (entry.second < least_steps) {
                least_steps = entry.second;
            }
        }

        return least_steps;
    }
}