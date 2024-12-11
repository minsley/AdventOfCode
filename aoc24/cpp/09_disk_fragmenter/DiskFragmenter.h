//
// Created by Matt Insley on 12/10/24.
//

#ifndef AOC24_DISKFRAGMENTER_H
#define AOC24_DISKFRAGMENTER_H

#include <vector>

namespace DiskFragmenter {
    struct Equation {
        int left;
        std::vector<int> right;
    };

    using InputSet = std::vector<Equation>;

    bool solveEq(int left, const std::vector<int> &right);

    int solve1(const InputSet &input);
}
#endif //AOC24_DISKFRAGMENTER_H
