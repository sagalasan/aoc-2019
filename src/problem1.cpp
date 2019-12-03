#include <iostream>
#include <vector>
#include <string>
#include <fstream>

std::vector<long long> load_part1() {
    std::vector<long long> result;
    std::ifstream file("../resources/p01_1.txt");

    std::string line;
    while (std::getline(file, line)) {
        result.push_back(std::stoull(line));
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

long long part1() {
    std::vector<long long> masses = load_part1();

    long long total_mass = 0;
    for (long long mass : masses) {
        total_mass += count_fuel(mass);
    }

    return total_mass;
}

long long part2() {
    std::vector<long long> masses = load_part1();

    long long total_mass = 0;
    for (long long mass : masses) {
        total_mass += count_fuel_rec(mass);
    }

    return total_mass;
}

int main() {
    std::cout << "aoc p01 - 1: " << part1() << std::endl;
    std::cout << "aoc p01 - 2: " << part2() << std::endl;
}