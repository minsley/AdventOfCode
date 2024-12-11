//
// Created by Matt Insley on 12/10/24.
//

#include "ResonantCollinearity.h"

size_t ResonantCollinearity::solve1(const Map &input) {
    // antinodes may overlap, so only track unique locations
    auto hash = [](const Coord& p) { return std::hash<size_t>()(p.x) * 31 + std::hash<size_t>()(p.y); };
    auto equal = [](const Coord& p1, const Coord& p2) { return p1.x == p2.x && p1.y == p2.y; };
    std::unordered_set<Coord, decltype(hash), decltype(equal)> uniqueLoc(0, hash, equal);

    for (const auto &band : input.antennae) {
        // takes 2 to tango
        if(band.second.size() < 2) continue;

        // pairwise combination of all antennae in same band
        // should have n_antinodes = 2 * C(n_antennae, 2)
        for (size_t i=0; i<band.second.size(); i++) {
            for (size_t j=i+1; j<band.second.size(); j++) {
                Coord a1 = band.second[i];
                Coord a2 = band.second[j];
                size_t dx = a1.x - a2.x ;
                size_t dy = a1.y - a2.y;

                auto c1 = Coord(a1.x + dx, a1.y + dy);
                auto c2 = Coord(a2.x - dx, a2.y - dy);

                // check bounds, then add to unique set
                if(c1.x >= 0 && c1.x < input.width && c1.y >= 0 && c1.y < input.height) {
                    uniqueLoc.insert(c1);
                }

                if(c2.x >= 0 && c2.x < input.width && c2.y >= 0 && c2.y < input.height) {
                    uniqueLoc.insert(c2);
                }
            }
        }
    }

    return uniqueLoc.size();
}

size_t ResonantCollinearity::solve2(const Map &input) {
    // antinodes may overlap, so only track unique locations
    auto hash = [](const Coord& p) { return std::hash<size_t>()(p.x) * 31 + std::hash<size_t>()(p.y); };
    auto equal = [](const Coord& p1, const Coord& p2) { return p1.x == p2.x && p1.y == p2.y; };
    std::unordered_set<Coord, decltype(hash), decltype(equal)> uniqueLoc(0, hash, equal);

    for (const auto &band : input.antennae) {
        // takes 2 to tango
        if(band.second.size() < 2) continue;

        // pairwise combination of all antennae in same band
        for (size_t i=0; i<band.second.size(); i++) {
            for (size_t j=i+1; j<band.second.size(); j++) {
                Coord a1 = band.second[i];
                Coord a2 = band.second[j];
                size_t dx = a1.x - a2.x ;
                size_t dy = a1.y - a2.y;

                // step both directions, adding as many nodes as will fit
                // note: every antenna pair will also have overlapping antinodes now!
                auto c1 = Coord(a1.x, a1.y);
                while(c1.x >= 0 && c1.x < input.width && c1.y >= 0 && c1.y < input.height) {
                    uniqueLoc.insert(c1);
                    c1.x += dx;
                    c1.y += dy;
                }

                auto c2 = Coord(a2.x, a2.y);
                while(c2.x >= 0 && c2.x < input.width && c2.y >= 0 && c2.y < input.height) {
                    uniqueLoc.insert(c2);
                    c2.x -= dx;
                    c2.y -= dy;
                }
            }
        }
    }

    return uniqueLoc.size();
}