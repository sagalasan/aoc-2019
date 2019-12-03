#include <iostream>
#include <vector>
#include <stdexcept>
#include <fstream>

std::vector<unsigned long> load_part1() {
    std::vector<unsigned long> result;
    std::ifstream file("../resources/p02_1.txt");

    std::string raw_value;
    while (std::getline(file, raw_value, ',')) {
        result.push_back(std::stoul(raw_value));
    }

    return result;
}

void run_add(std::vector<unsigned long>& program, unsigned long& index) {
    program[program[index + 3]] = program[program[index + 1]] + program[program[index + 2]];
    index += 4;
}

void run_mul(std::vector<unsigned long>& program, unsigned long& index) {
    program[program[index + 3]] = program[program[index + 1]] * program[program[index + 2]];
    index += 4;
}

void run_intcode(std::vector<unsigned long>& program) {
    unsigned long index = 0;

    while (index < program.size()) {
        unsigned long opcode = program[index];
        switch (opcode) {
            case 1:
                run_add(program, index);
                break;
            case 2:
                run_mul(program, index);
                break;
            case 99:
                return;
            default:
                throw std::runtime_error("Invalid opcode: " + std::to_string(opcode));
        }
    }
}

unsigned long part1() {
    std::vector<unsigned long> program = load_part1();

    program[1] = 12;
    program[2] = 2;

    run_intcode(program);

    return program[0];
}

int main() {
    std::cout << "aoc p02 - 1: " << part1() << std::endl;

    return 0;
}