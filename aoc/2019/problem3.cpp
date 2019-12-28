#include <iostream>
#include <vector>
#include <tuple>

enum class Direction {
    HORIZONTAL, VERTICAL
};

enum class Wire {
    EMPTY = 0,
    HORIZONTAL,
    VERTICAL,
    CORNER,
    CROSSED,
    ORIGIN,
};

class FrontPanel {
public:
    explicit FrontPanel()
    : size_x_(1),
    size_y_(1),
    panel_(std::vector<std::vector<Wire>>(1, std::vector<Wire>(1, Wire::ORIGIN))),
    central_port_x_(0),
    central_port_y_(0)
    {}

    void run_path(const std::vector<std::string>& path) {
        Direction direction;
        long count;
        for (const auto& raw_instruction : path) {
            std::tie(direction, count) = parse_instruction(raw_instruction);
            ensure_size(direction, count);
        }
    }
private:
    void ensure_size(const Direction& direction, const long& count) {

    }

    static std::pair<Direction, long> parse_instruction(const std::string& instruction) {
        if (instruction.size() < 2) {
            throw std::runtime_error("instruction must be at least 2 characters");
        }

        long count = std::stol(instruction.substr(1));
        switch (instruction[0]) {
            case 'U':
                return std::make_pair(Direction::VERTICAL, -count);
            case 'D':
                return std::make_pair(Direction::VERTICAL, count);
            case 'L':
                return std::make_pair(Direction::HORIZONTAL, -count);
            case 'R':
                return std::make_pair(Direction::HORIZONTAL, count);
            default:
                throw std::runtime_error("Invalid direction " + std::to_string(instruction[0]));
        }
    }

    std::vector<std::vector<Wire>> panel_;
    unsigned long size_x_;
    unsigned long size_y_;

    unsigned long central_port_x_;
    unsigned long central_port_y_;
};


int main() {

    return 0;
}