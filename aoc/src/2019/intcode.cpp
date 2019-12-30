#include <stdexcept>
#include "2019/intcode.h"

using namespace aoc::year_2019;

namespace aoc::year_2019 {
    std::uint64_t Intcode::run_program() {
        while (instruction_ptr_ < memory_.size()) {
            OpCode code = opcode(memory_[instruction_ptr_]);

            switch (code) {
                case OpCode::ADD:
                    run_add();
                    break;
                case OpCode::MUL:
                    run_mul();
                    break;
                case OpCode::TERMINATE:
                    return memory_[0];
                case OpCode::INVALID:
                    throw std::runtime_error("Invalid opcode: " +
                    std::to_string(memory_[instruction_ptr_]));
            }

            instruction_ptr_ += num_params(code) + 1;
        }

        throw std::runtime_error("Reached end of memory");
    }

    std::uint64_t Intcode::get_addr(std::uint64_t address) {
        return memory_[address];
    }

    void Intcode::set_addr(std::uint64_t address, std::uint64_t value) {
        memory_[address] = value;
    }

    const std::vector<std::uint64_t> & Intcode::get_mem() {
        return memory_;
    }

    std::uint64_t Intcode::mem_size() {
        return memory_.size();
    }

    void Intcode::reset_mem() {
        memory_ = memory_orig_;
        instruction_ptr_ = 0;
    }

    void Intcode::run_add() {
        memory_[memory_[instruction_ptr_ + 3]] = memory_[memory_[instruction_ptr_ + 1]] +
                                                 memory_[memory_[instruction_ptr_ + 2]];
    }

    void Intcode::run_mul() {
        memory_[memory_[instruction_ptr_ + 3]] = memory_[memory_[instruction_ptr_ + 1]] *
                                                 memory_[memory_[instruction_ptr_ + 2]];
    }

    OpCode Intcode::opcode(std::uint64_t code) {
        switch (code) {
            case 1: return OpCode::ADD;
            case 2: return OpCode::MUL;
            case 99: return OpCode::TERMINATE;
            default: return OpCode::INVALID;
        }
    }

    std::uint64_t Intcode::num_params(const OpCode& code) {
        switch (code) {
            case OpCode::ADD: return 3;
            case OpCode::MUL: return 3;
            case OpCode::TERMINATE: return 1;
            case OpCode::INVALID: return 0;
        }

        throw std::runtime_error("unreachable");
    }
}