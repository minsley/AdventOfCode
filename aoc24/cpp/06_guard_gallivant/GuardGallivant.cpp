//
// Created by Matt Insley on 12/5/24.
//

#include <sstream>
#include "GuardGallivant.h"
#include <unordered_set>
#include <iostream>

using namespace guard_gallivant;

Direction caratToDir(const char &c) {
    switch (c) {
        case '>': return RIGHT;
        case 'v': return DOWN;
        case '<': return LEFT;
        case '^': return UP;
        default: throw std::invalid_argument("invalid character");
    }
}

char dirToCarat(const Direction d) {
    switch (d) {
        case UP:    return '^';
        case RIGHT: return '>';
        case DOWN:  return 'v';
        case LEFT:  return '<';
        default: throw std::invalid_argument("invalid direction");
    }
}

bool isCarat(const char &c) {
    return c == '^' || c == '>' || c == 'v' || c == '<';
}

Board guard_gallivant::parse(const std::string &inputStr) {
    auto result = Board();
    std::vector<std::pair<char,int>> row;
    for(auto &c : inputStr) {
        if(c == '\n') {
            result.map.push_back(row);
            row.clear();
        } else if (isCarat(c)) {
            result.startDir = caratToDir(c);
            result.startPos = Position {
                .y = static_cast<int>(result.map.size()),
                .x = static_cast<int>(row.size())
            };
            row.emplace_back('.',0);
        } else {
            row.emplace_back(c,0);
        }
    }
    return result;
}

void move(Position &pos, const Direction dir) {
    switch(dir) {
        case UP:    pos.y--; break;
        case RIGHT: pos.x++; break;
        case DOWN:  pos.y++; break;
        case LEFT:  pos.x--; break;
        default:
            throw std::invalid_argument("invalid direction");
    }
}

Direction inverse(const Direction dir) {
    switch(dir) {
        case UP:    return DOWN;
        case RIGHT: return LEFT;
        case DOWN:  return UP;
        case LEFT:  return RIGHT;
        default:
            throw std::invalid_argument("invalid direction");
    }
}

void printDebug(const Map &map, const int posTally) {
    std::cout << std::endl << std::endl << std::endl;
    for (auto &row : map) {
        for (const auto & [glyph, visits] : row) {
            std::cout << glyph;
        }
        std::cout << std::endl;
    }
    std::cout << "Unique Positions: " << posTally << std::endl;
}

int guard_gallivant::solve1(Board &board, const bool debug) {
    Position pos = board.startPos;
    Direction dir = board.startDir;
    char carat = dirToCarat(dir);
    int uniquePos = 0;

    while (pos.y < board.map.size() && pos.y >= 0 && pos.x < board.map[pos.y].size() && pos.x >= 0) {
        std::pair<char,int> &loc = board.map[pos.y][pos.x];

        if(loc.first == '#') {
            // back up a step, turn 90deg clockwise, step
            move(pos, inverse(dir));
            dir = static_cast<Direction>((static_cast<int>(dir) + 1) % 4);
            carat = dirToCarat(dir);
            move(pos, dir);

            if(debug) printDebug(board.map, uniquePos);
        } else if (loc.first == carat) {
            // we're caught in a loop, worst guard duty gig ever
            return uniquePos;
        } else {
            // track first time traversing
            if(loc.second == 0) uniquePos++;

            // if we ever do a crossover, spot is no longer unique
            // if(loc.second == 1) uniquePos--;

            // mark where we've been
            loc.first = carat;
            loc.second += 1;

            move(pos, dir);
        }
    }

    if(debug) printDebug(board.map, uniquePos);
    return uniquePos;
}

int guard_gallivant::solve2(Board &board, const bool debug) {
    return -1;
}