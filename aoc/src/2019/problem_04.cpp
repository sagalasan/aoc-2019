#include <string>
#include <tuple>
#include <unordered_map>
#include <iostream>

namespace {
    std::pair<std::uint64_t, std::uint64_t> parse_input(const std::string& input) {
        auto d_idx = input.find('-');

        std::uint64_t first = std::stoull(input.substr(0, d_idx));
        std::uint64_t second = std::stoull(input.substr(d_idx + 1));

        return std::make_pair(first, second);
    }
}

namespace aoc::year_2019::day04 {
    bool is_valid_pass(const std::string& password) {
        if (password.size() != 6) return false;

        bool has_adj = false;
        for (std::size_t i = 1; i < password.size(); ++i) {
            char first = password[i - 1];
            char second = password[i];

            if (!has_adj && first == second) {
                has_adj = true;
            }

            if (second < first) return false;
        }

        return has_adj;
    }

    bool is_valid_pass2(const std::string& password) {
        if (password.size() != 6) return false;

        std::unordered_map<char, std::size_t> adj_count;
        for (std::size_t i = 1; i < password.size(); ++i) {
            char first = password[i - 1];
            char second = password[i];

            if (second < first) return false;

            if (first == second) {
                auto [iter, success] = adj_count.try_emplace(first, 1);
                iter->second += 1;
            }
        }

        for (const auto& [c, count] : adj_count) {
            if (count == 2) return true;
        }

        return false;
    }

    std::size_t part1(const std::string& input) {
        std::size_t result = 0;

        std::uint64_t start, end;
        std::tie(start, end) = parse_input(input);

        for (std::uint64_t i = start; i <= end; ++i) {
            std::string pass = std::to_string(i);

            if (is_valid_pass(pass)) ++result;
        }

        return result;
    }

    std::size_t part2(const std::string& input) {
        std::size_t result = 0;

        std::uint64_t start, end;
        std::tie(start, end) = parse_input(input);

        for (std::uint64_t i = start; i <= end; ++i) {
            std::string pass = std::to_string(i);

            if (is_valid_pass2(pass)) ++result;
        }

        return result;
    }
}