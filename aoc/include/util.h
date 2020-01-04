#ifndef AOC_2019_UTIL_H
#define AOC_2019_UTIL_H

#include <cstddef>
#include <string>

//namespace aoc {
//    struct pair_hash {
//        template <typename T1, typename T2>
//        inline std::size_t operator()(const std::pair<T1, T2>& x) const {
//            return std::hash<T1>(x.first) ^ std::hash<T2>(x.second);
//        }
//    };
//}

template <typename T>
std::string left_pad(const T& value, std::size_t length) {
    return left_pad(value, length, '0');
}

template <typename T>
std::string left_pad(const T& value, std::size_t length, char pad_char) {
    auto str = std::to_string(value);
    if (str.length() < length) {
        str.insert(str.front() == '-' ? 1 : 0, length - str.length(), pad_char);
    }
    return str;
}

#endif //AOC_2019_UTIL_H
