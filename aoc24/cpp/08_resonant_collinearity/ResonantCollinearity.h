//
// Created by Matt Insley on 12/10/24.
//

#ifndef AOC24_RESONANTCOLLINEARITY_H
#define AOC24_RESONANTCOLLINEARITY_H

#include <vector>

namespace ResonantCollinearity {
    struct Equation {
        int left;
        std::vector<int> right;
    };

    using InputSet = std::vector<Equation>;

    bool solveEq(int left, const std::vector<int> &right);
    int solve1(const InputSet &input);
}
#endif //AOC24_RESONANTCOLLINEARITY_H
