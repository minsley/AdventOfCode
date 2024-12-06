//
// Created by Matt Insley on 12/5/24.
//

#ifndef GUARDGALLIVANT_H
#define GUARDGALLIVANT_H

#include <vector>
#include <string>

namespace guard_gallivant {

    using Map = std::vector<std::vector<char>>;

    enum Direction {
        UP,
        RIGHT,
        DOWN,
        LEFT
    };

    struct Position {
    public:
        int y;
        int x;
    };

    class Board {
    public:
        Map map;
        Position startPos;
        Direction startDir;
    };

    Board parse(const std::string &inputStr);
    int solve1(Board &board);
    int solve2(Board &board);
}


#endif //GUARDGALLIVANT_H
