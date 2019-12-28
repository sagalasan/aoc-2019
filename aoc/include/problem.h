#ifndef AOC_2019_PROBLEM_H
#define AOC_2019_PROBLEM_H

#include <variant>
#include <functional>

namespace aoc {
    using Result = std::variant<std::int64_t, std::size_t, std::string>;
    using Problem = std::function<Result (std::string&)>;

    struct ProblemSet {
        std::vector<Problem> problems;
        std::string input_path;
    };

//    std::optional<Problem> get_problem(std::size_t year, std::size_t problem, std::size_t part);

//    void register_problem(std::size_t year, std::size_t problem, std::size_t part, const Problem& aoc_problem);
//
//    namespace impl {
//        struct Registrator {
//            Registrator(std::size_t year, std::size_t problem, std::size_t part, const Problem& aoc_problem) {
//                register_problem(year, problem, part, aoc_problem);
//            }
//        };
//    }
}

//#define REGISTER_AOC_PROBLEM(year, problem, part, aoc_problem) \
//    static const aoc::impl::Registrator registrator_##part(year, problem, part, aoc_problem)

#endif //AOC_2019_PROBLEM_H
