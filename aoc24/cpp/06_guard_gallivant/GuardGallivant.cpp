//
// Created by Matt Insley on 12/5/24.
//

#include <sstream>
#include "GuardGallivant.h"
#include <unordered_set>
#include <iostream>

using namespace guard_gallivant;

Board guard_gallivant::parse(const std::string &inputStr) {
    Board result = Board();
    std::vector<char> row;
    bool setGuardPos = false;
    for(auto &c : inputStr) {
        if(c == '\n') {
            result.map.push_back(row);
            row.clear();
        } else {
            if (c == '^') {
                result.startDir = Direction::UP;
                setGuardPos = true;
            } else if (c == '>') {
                result.startDir = Direction::RIGHT;
                setGuardPos = true;
            } else if (c == 'v') {
                result.startDir = Direction::DOWN;
                setGuardPos = true;
            } else if (c == '<') {
                result.startDir = Direction::LEFT;
                setGuardPos = true;
            }

            if(setGuardPos) {
                setGuardPos = false;
                result.startPos = Position {
                        .y = static_cast<int>(result.map.size()),
                        .x = static_cast<int>(row.size())
                };
                row.push_back('.');
            } else {
                row.push_back(c);
            }
        }
    }
    return result;
}

int guard_gallivant::solve1(Board &board) {
    Position pos = board.startPos;
    Direction dir = board.startDir;
    int uniquePos = 0;

    while (pos.y < board.map.size() && pos.y >= 0 && pos.x < board.map[pos.y].size() && pos.x >= 0) {
        char c = board.map[pos.y][pos.x];

        if(c == '#') {
            // back up a step
            if (dir == Direction::UP) {
                pos.y++;
            } else if (dir == Direction::RIGHT) {
                pos.x--;
            } else if (dir == Direction::DOWN) {
                pos.y--;
            } else if (dir == Direction::LEFT) {
                pos.x++;
            }
            // turn 90deg clockwise
            dir = (Direction)(((int)dir + 1) % 4);
        } else {
            // mark places we've been
            if(c == '.') {
                board.map[pos.y][pos.x] = 'X';
                uniquePos++;
            }

            if (dir == Direction::UP) {
                pos.y--;
            } else if (dir == Direction::RIGHT) {
                pos.x++;
            } else if (dir == Direction::DOWN) {
                pos.y++;
            } else if (dir == Direction::LEFT) {
                pos.x--;
            }
        }

        std::cout << std::endl << std::endl << std::endl;
        for (auto &row : board.map) {
            for (auto &c : row) {
                std::cout << c;
            }
            std::cout << std::endl;
        }
    }

    return uniquePos;
}

int guard_gallivant::solve2(Board &board) {
    return -1;
}