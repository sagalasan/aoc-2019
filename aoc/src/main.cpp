#include <problem.h>
#include <2019/problem_01.h>
#include <fstream>


std::vector<aoc::ProblemSet> runners = {
        aoc::ProblemSet {
                {aoc::year_2019::day01_part1, aoc::year_2019::day01_part2},
                "../resources/p01_1.txt"
        }
};

int main() {
    for (const auto& runner : runners) {
        // Load input file
        std::ifstream file(runner.input_path);


    }

    return 0;
}