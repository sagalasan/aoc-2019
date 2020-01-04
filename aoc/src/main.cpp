#include <iostream>
#include <problem.h>
#include <2019/problem_01.h>
#include <2019/problem_02.h>
#include <2019/problem_03.h>
#include <fstream>
#include <map>
#include "util.h"

#define NUM_PROBLEMS 25

const std::map<std::size_t, std::vector<aoc::Problem>> problem_map = {
        {1, {aoc::year_2019::day01_part1, aoc::year_2019::day01_part2}},
        {2, {aoc::year_2019::day02::part1, aoc::year_2019::day02::part2}},
        {3, {aoc::year_2019::day03::part1, aoc::year_2019::day03::part2}}
};

std::string read_input(std::uint32_t day) {
    std::string path = "./aoc/resources/p" + std::to_string(day) + ".txt";
    std::fstream file(path);

    file.seekg(0, std::ios::end);
    std::size_t size = file.tellg();
    std::string str(size, ' ');
    file.seekg(0, std::ios::beg);

    file.read(&str[0], size);
    return str;
}

int main() {
    for (const auto& entry : problem_map) {
        auto day = entry.first;
        auto problems = entry.second;
        std::cout << "Aoc 2019: Day " << day << std::endl;

        std::string input = read_input(day);

        for (std::size_t i = 0; i < problems.size(); ++i) {
            auto problem = problems[i];
            auto result = problem(input);

            std::cout << "  Part " << std::to_string(i + 1) << ": ";
            std::visit([](const auto& arg) { std::cout << arg; }, result);
            std::cout << std::endl;
        }
    }

    return 0;
}