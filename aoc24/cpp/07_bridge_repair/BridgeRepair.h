//
// Created by Matt Insley on 12/7/24.
//

#ifndef AOC24_BRIDGEREPAIR_H
#define AOC24_BRIDGEREPAIR_H

#include <vector>

namespace BridgeRepair {
    struct Equation {
        int left;
        std::vector<int> right;
    };

    using InputSet = std::vector<Equation>;

    bool solveEq(int left, const std::vector<int> &right);
    int solve1(const InputSet &input);
}
#endif //AOC24_BRIDGEREPAIR_H
