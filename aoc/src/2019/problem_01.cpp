#include <problem.h>
#include "2019/problem_01.h"

namespace aoc::year_2019::problem_01 {
    std::vector<long long> parse_input(std::istream& input) {
        std::vector<long long> result;

        std::string line;
        while (std::getline(input, line)) {
            result.push_back(std::stoll(line));
        }

        return result;
    }

    inline long long count_fuel(long long mass) {
        return (mass / 3) - 2;
    }

    long long count_fuel_rec(long long mass) {
        long long fuel_mass = count_fuel(mass);
        long long mass_sum = 0;

        while (fuel_mass > 0) {
            mass_sum += fuel_mass;
            fuel_mass = count_fuel(fuel_mass);
        }

        return mass_sum;
    }

    std::size_t part1(std::istream &input) {
        std::vector<long long> masses = parse_input(input);

        std::size_t total_mass = 0;
        for (long long mass : masses) {
            total_mass += count_fuel(mass);
        }

        return total_mass;
    }

    std::size_t part2(std::istream &input) {
        std::vector<long long> masses = parse_input(input);

        std::size_t total_mass = 0;
        for (long long mass : masses) {
            total_mass += count_fuel_rec(mass);
        }

        return total_mass;
    }

    REGISTER_AOC_PROBLEM(2019, 1, 1, part1);
    REGISTER_AOC_PROBLEM(2019, 1, 2, part2);
}