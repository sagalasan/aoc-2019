#include <stdexcept>
#include <sstream>
#include "2019/intcode.h"

using namespace aoc::year_2019;

namespace aoc::year_2019 {
    std::vector<std::int64_t> parse_intcode(const std::string& input) {
        std::vector<std::int64_t> result;
        std::istringstream stream(input);

        std::string raw_value;
        while (std::getline(stream, raw_value, ',')) {
            result.push_back(std::stoull(raw_value));
        }

        return result;
    }


    OpCode opcode(std::int64_t code) {
        switch (code) {
            case 1: return OpCode::ADD;
            case 2: return OpCode::MUL;
            case 3: return OpCode::GET_INPUT;
            case 4: return OpCode::SET_OUTPUT;
            case 99: return OpCode::TERMINATE;
            default: return OpCode::INVALID;
        }
    }

    std::size_t num_params(const OpCode& code) {
        switch (code) {
            case OpCode::ADD: return 3;
            case OpCode::MUL: return 3;
            case OpCode::GET_INPUT: return 1;
            case OpCode::SET_OUTPUT: return 1;
            case OpCode::TERMINATE: return 1;
            case OpCode::INVALID: return 0;
        }

        throw std::runtime_error("unreachable");
    }

    ParameterMode param_mode(std::int64_t mode) {
        switch (mode) {
            case 0: return ParameterMode::POSITION;
            case 1: return ParameterMode::IMMEDIATE;
            default: return ParameterMode::INVALID;
        }
    }

    std::int64_t Intcode::run_program() {
        while (instruction_ptr_ < memory_.size()) {
            std::int64_t raw_code = memory_[instruction_ptr_];
            std::int64_t raw_modes = raw_code / 100;

            OpCode code = opcode(raw_code % 100);
            std::int64_t increment;
            switch (code) {
                case OpCode::ADD:
                    increment = run_add(get_modes<3>(raw_modes));
                    break;
                case OpCode::MUL:
                    increment = run_mul(get_modes<3>(raw_modes));
                    break;
                case OpCode::GET_INPUT:
                    increment = run_input(get_modes<1>(raw_modes)[0]);
                    break;
                case OpCode::SET_OUTPUT:
                    increment = run_output(get_modes<1>(raw_modes)[0]);
                    break;
                case OpCode::TERMINATE:
                    return memory_[0];
                case OpCode::INVALID:
                    throw std::runtime_error("Invalid opcode: " +
                    std::to_string(memory_[instruction_ptr_]));
            }

            instruction_ptr_ += increment;
        }

        throw std::runtime_error("Reached end of memory");
    }

    std::int64_t Intcode::get_addr(std::int64_t address) {
        return memory_[address];
    }

    std::int64_t& Intcode::get_param(std::int64_t address, const ParameterMode &mode) {
        switch (mode) {
            case ParameterMode::POSITION:
                return memory_[memory_[address]];
            case ParameterMode::IMMEDIATE:
                return memory_[address];
            case ParameterMode::INVALID:
                throw std::runtime_error("Invalid parameter mode");
        }

        throw std::runtime_error("unreachable");
    }

    void Intcode::set_addr(std::int64_t address, std::int64_t value) {
        memory_[address] = value;
    }

    const std::vector<std::int64_t> & Intcode::get_mem() {
        return memory_;
    }

    std::int64_t Intcode::mem_size() {
        return memory_.size();
    }

    void Intcode::reset_mem() {
        memory_ = memory_orig_;
        instruction_ptr_ = 0;
    }

    std::int64_t Intcode::run_add(const std::array<ParameterMode, 3>& modes) {
        get_param(instruction_ptr_ + 3, modes[2]) = get_param(instruction_ptr_ + 1, modes[0]) +
                get_param(instruction_ptr_ + 2, modes[1]);
        return 4;
    }

    std::int64_t Intcode::run_mul(const std::array<ParameterMode, 3>& modes) {
        get_param(instruction_ptr_ + 3, modes[2]) = get_param(instruction_ptr_ + 1, modes[0]) *
                get_param(instruction_ptr_ + 2, modes[1]);
        return 4;
    }

    std::int64_t Intcode::run_input(const aoc::year_2019::ParameterMode &mode) {
        auto input = get_input();
        if (!input.has_value()) {
            throw std::runtime_error("No more inputs");
        }

        get_param(instruction_ptr_ + 1, mode) = *input;
        return 2;
    }

    std::int64_t Intcode::run_output(const aoc::year_2019::ParameterMode &mode) {
        add_output(get_param(instruction_ptr_ + 1, mode));
        return 2;
    }

    std::int64_t Intcode::run_jump_if_true(const std::array<ParameterMode, 2> &modes) {
        
    }
}