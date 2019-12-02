#include <iostream>
#include <vector>
#include <string>
#include <fstream>

std::vector<unsigned long long> load_part1() {
    std::vector<unsigned long long> result;
    std::ifstream file("../resources/p01_1.txt");

    std::string line;
    while (std::getline(file, line)) {
        result.push_back(std::stoull(line));
    }

    return result;
}

inline unsigned long long count_fuel(unsigned long long mass) {
    return (mass / 3) - 2;
}

unsigned long long part1() {
    std::vector<unsigned long long> masses = load_part1();
    std::vector<unsigned long long> fuels(masses.size());

    for (auto i = 0; i < masses.size(); ++i) {
        fuels[i] = count_fuel(masses[i]);
    }

    unsigned long long total_mass = 0;
    for (unsigned long long fuel : fuels) {
        total_mass += fuel;
    }

    return total_mass;
}

int main() {
//    std::cout << "12: " << count_fuel(12) << std::endl;
//    std::cout << "14: " << count_fuel(14) << std::endl;
//    std::cout << "1969: " << count_fuel(1969) << std::endl;
//    std::cout << "100756: " << count_fuel(100756) << std::endl;

    std::cout << "aoc p01 - 1: " << part1() << std::endl;
}