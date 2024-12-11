//
// Created by Matt Insley on 12/10/24.
//

#ifndef AOC24_RESONANTCOLLINEARITY_H
#define AOC24_RESONANTCOLLINEARITY_H

#include <vector>
#include <map>
#include <unordered_set>
#include <iostream>

namespace ResonantCollinearity {
    struct Coord {
        size_t x;
        size_t y;
    };
    struct Map {
        size_t height = 0;
        size_t width = 0;
        std::map<char, std::vector<Coord>> antennae;
    };

    size_t solve1(const Map &input);
    size_t solve2(const Map &input);
}
#endif //AOC24_RESONANTCOLLINEARITY_H
