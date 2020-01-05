#ifndef AOC_2019_INTCODE_H
#define AOC_2019_INTCODE_H

#include <cstddef>
#include <vector>
#include <cstdint>
#include <array>
#include <deque>
#include <optional>

namespace aoc::year_2019 {
    std::vector<std::int64_t> parse_intcode(const std::string& input);

    enum class OpCode {
        ADD,
        MUL,
        GET_INPUT,
        SET_OUTPUT,
        JUMP_IF_TRUE,
        JUMP_IF_FALSE,
        LESS_THAN,
        EQUALS,
        TERMINATE,
        INVALID,
    };

    enum class ParameterMode {
        POSITION, IMMEDIATE, INVALID,
    };

    template <std::size_t N>
    struct Instruction {
        OpCode code;
        std::array<ParameterMode, N> modes;
    };

    ParameterMode param_mode(std::int64_t mode);
    OpCode opcode(std::int64_t code);
    std::size_t num_params(const OpCode& code);

    template <std::size_t N>
    std::array<ParameterMode, N> get_modes(std::size_t modes) {
        std::array<ParameterMode, N> result;

        for (std::size_t i = 0; i < N; ++i) {
            result[i] = param_mode(modes % 10);
            modes /= 10;
        }

        return result;
    }

    class Intcode {
    public:
        explicit Intcode(std::vector<std::int64_t> memory)
                : memory_(std::move(memory)),
                  instruction_ptr_(0) {
            memory_orig_ = memory_;
        }

        std::int64_t run_program();

        void set_addr(std::int64_t address, std::int64_t value);

        std::int64_t get_addr(std::int64_t address);

        std::int64_t& get_param(std::int64_t address, const ParameterMode& mode);

        const std::vector<std::int64_t> &get_mem();

        std::int64_t mem_size();

        void reset_mem();

        void push_input(std::int64_t input) {
            input_.push_back(input);
        }

        template <typename InputIt>
        void push_input(InputIt begin, InputIt end) {
            while (begin != end) {
                input_.push_back(*begin);
            }
        }

        const std::vector<std::int64_t>& get_output() {
            return output_;
        }
    private:
        std::optional<std::int64_t> get_input() {
            if (input_.empty()) return {};

            auto front = input_.front();
            input_.pop_front();
            return front;
        }

        void add_output(std::int64_t output) {
            output_.push_back(output);
        }

        std::int64_t run_add(const std::array<ParameterMode, 3>& modes);
        std::int64_t run_mul(const std::array<ParameterMode, 3>& modes);
        std::int64_t run_input(const ParameterMode& mode);
        std::int64_t run_output(const ParameterMode& mode);
        std::int64_t run_jump_if_true(const std::array<ParameterMode, 2>& modes);
        std::int64_t run_jump_if_false(const std::array<ParameterMode, 2>& modes);
        std::int64_t run_less_than(const std::array<ParameterMode, 3>& modes);
        std::int64_t run_equals(const std::array<ParameterMode, 3>& modes);

        std::deque<std::int64_t> input_;
        std::vector<std::int64_t> output_;

        std::vector<std::int64_t> memory_;
        std::vector<std::int64_t> memory_orig_;
        std::int64_t instruction_ptr_;
    };
}

#endif //AOC_2019_INTCODE_H
