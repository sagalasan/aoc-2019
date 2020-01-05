#include <problem.h>
#include <2019/intcode.h>
#include <sstream>

namespace aoc::year_2019::day02 {
    std::size_t part1(const std::string& input) {
        std::vector<std::int64_t> program = parse_intcode(input);

        Intcode intcode(program);
        intcode.set_addr(1, 12);
        intcode.set_addr(2, 2);

        return intcode.run_program();
    }

    std::size_t part2(const std::string& input) {
        std::vector<std::int64_t> program = parse_intcode(input);

        Intcode intcode(program);

        for (std::uint64_t noun = 0; noun < intcode.mem_size(); ++noun) {
            for (std::uint64_t verb = 0; verb < intcode.mem_size(); ++verb) {
                intcode.reset_mem();

                intcode.set_addr(1, noun);
                intcode.set_addr(2, verb);

                std::uint64_t result = intcode.run_program();

                if (result == 19690720) {
                    return 100 * noun + verb;
                }
            }
        }

        throw std::runtime_error("No solution found");
    }
}