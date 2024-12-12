//
// Created by Matt Insley on 12/11/24.
//

#include "PlutonianPebbles.h"

void PlutonianPebbles::blink(std::vector<long> &input) {
    for (auto j = input.begin(); j != input.end(); ++j) {
        // 0 -> 1
        if (*j == 0) {
            *j = 1;
            continue;
        }

        // even len are split
        if (const auto s = std::to_string(*j); s.length() % 2 == 0) {
            *j = std::stoi(s.substr(0, s.length()/2));
            j = input.insert(j+1, std::stoi(s.substr(s.length()/2)));
            continue;
        }

        // else multiply by 2024
        *j = *j * 2024;
    }
}

size_t PlutonianPebbles::solve1(const std::vector<long> &input, size_t blinks) {

    // copy input cuz were gonna work in the vec
    std::vector<long> workingCopy;
    std::ranges::copy(input, std::back_inserter(workingCopy));

    std::cout << 0 << ": " << workingCopy.size() << std::endl;

    for (size_t i = 0; i < blinks; i++) {
        blink(workingCopy);
        std::cout << i+1 << ": " << workingCopy.size() << std::endl;
    }

    return workingCopy.size();
}