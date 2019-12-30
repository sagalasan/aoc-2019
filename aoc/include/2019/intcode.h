#ifndef AOC_2019_INTCODE_H
#define AOC_2019_INTCODE_H

#include <cstddef>
#include <vector>
#include <cstdint>

namespace aoc::year_2019 {
    enum class OpCode {
        ADD,
        MUL,
        TERMINATE,
        INVALID,
    };

    class Intcode {
    public:
        explicit Intcode(std::vector<std::uint64_t> memory)
                : memory_(std::move(memory)),
                  instruction_ptr_(0) {
            memory_orig_ = memory_;
        }

        std::uint64_t run_program();

        void set_addr(std::uint64_t address, std::uint64_t value);

        std::uint64_t get_addr(std::uint64_t address);

        const std::vector<std::uint64_t> &get_mem();

        std::uint64_t mem_size();

        void reset_mem();

    private:
        void run_add();

        void run_mul();

        OpCode opcode(std::uint64_t code);
        std::uint64_t num_params(const OpCode& code);

        std::vector<std::uint64_t> memory_;
        std::vector<std::uint64_t> memory_orig_;
        std::uint64_t instruction_ptr_;
    };
}

#endif //AOC_2019_INTCODE_H
