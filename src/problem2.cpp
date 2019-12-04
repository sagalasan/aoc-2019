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

class IntcodeRunner {
public:
    explicit IntcodeRunner(std::vector<unsigned long> memory)
    : memory_(std::move(memory)),
      instruction_ptr_(0)
    {
        memory_orig_ = memory_;
    }

    unsigned long run_program() {
        while (instruction_ptr_ < memory_.size()) {
            switch(get_addr(instruction_ptr_)) {
                case 1:
                    run_add();
                    break;
                case 2:
                    run_mul();
                    break;
                case 99:
                    return get_addr(0);
                default:
                    throw std::runtime_error("Invalid opcode: " + std::to_string(get_addr(instruction_ptr_)));
            }
        }

        throw std::runtime_error("Reached end of memory");
    }

    void set_addr(unsigned long address, unsigned long value) {
        memory_[address] = value;
    }

    unsigned long get_addr(unsigned long address) {
        return memory_[address];
    }

    const std::vector<unsigned long>& get_mem() {
        return memory_;
    }

    unsigned long mem_size() {
        return memory_.size();
    }

    void reset_mem() {
        memory_ = memory_orig_;
        instruction_ptr_ = 0;
    }
private:
    void run_add() {
        memory_[memory_[instruction_ptr_ + 3]] = memory_[memory_[instruction_ptr_ + 1]] +
                memory_[memory_[instruction_ptr_ + 2]];
        instruction_ptr_ += 4;
    }

    void run_mul() {
        memory_[memory_[instruction_ptr_ + 3]] = memory_[memory_[instruction_ptr_ + 1]] *
                memory_[memory_[instruction_ptr_ + 2]];
        instruction_ptr_ += 4;
    }

    std::vector<unsigned long> memory_;
    std::vector<unsigned long> memory_orig_;
    unsigned long instruction_ptr_;
};

unsigned long part1() {
    std::vector<unsigned long> program = load_part1();

    IntcodeRunner runner(program);
    runner.set_addr(1, 12);
    runner.set_addr(2, 2);

    return runner.run_program();
}

unsigned long part2() {
    std::vector<unsigned long> program = load_part1();

    IntcodeRunner runner(program);

    for (unsigned long noun = 0; noun < runner.mem_size(); ++noun) {
        for (unsigned long verb = 0; verb < runner.mem_size(); ++verb) {
            runner.reset_mem();

            runner.set_addr(1, noun);
            runner.set_addr(2, verb);

            unsigned long result = runner.run_program();

            if (result == 19690720) {
                return 100 * noun + verb;
            }
        }
    }

    throw std::runtime_error("No solution found");
}

int main() {
    std::cout << "aoc p02 - 1: " << part1() << std::endl;
    std::cout << "aoc p02 - 2: " << part2() << std::endl;

    return 0;
}