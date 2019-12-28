#include <problem.h>
#include <sstream>
#include "2019/problem_01.h"

namespace aoc::year_2019 {
    std::vector<long long> parse_input(const std::string& input) {
        std::istringstream istream(input);
        std::vector<long long> result;

        std::string line;
        while (std::getline(istream, line)) {
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

    std::size_t day01_part1(const std::string& input) {
        std::vector<long long> masses = parse_input(input);

        std::size_t total_mass = 0;
        for (long long mass : masses) {
            total_mass += count_fuel(mass);
        }

        return total_mass;
    }

    std::size_t day01_part2(const std::string& input) {
        std::vector<long long> masses = parse_input(input);

        std::size_t total_mass = 0;
        for (long long mass : masses) {
            total_mass += count_fuel_rec(mass);
        }

        return total_mass;
    }


}