#include <string>
#include <vector>
#include <2019/intcode.h>

namespace aoc::year_2019::day05 {
    std::size_t part1(const std::string& input) {
        std::vector<std::int64_t> program = parse_intcode(input);

        Intcode intcode(program);
        intcode.push_input(1);

        intcode.run_program();

        const auto& output = intcode.get_output();

        return output[output.size() - 1];
    }

    std::size_t part2(const std::string& input) {
        return 0;
    }
}