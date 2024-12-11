//
// Created by Matt Insley on 12/7/24.
//

#ifndef AOC24_BRIDGEREPAIR_H
#define AOC24_BRIDGEREPAIR_H

#include <vector>
#include <span>
#include <cmath>

namespace BridgeRepair {
    struct Equation {
        long left;
        std::vector<long> right;
    };

    using InputSet = std::vector<Equation>;

    bool evalEq1(long solution, long state, std::span<const long> args);
    long solve1(InputSet &input);

    long pow10(long num, long pow);
    long concat(long a, long b);
    bool evalEq2(long solution, long state, std::span<const long> args);
    long solve2(InputSet &input);
}
#endif //AOC24_BRIDGEREPAIR_H
