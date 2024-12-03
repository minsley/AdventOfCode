//
// Created by mins on 12/2/2024.
//

#ifndef MULLITOVER_H
#define MULLITOVER_H

#include <string>
#include <vector>

namespace MullItOver {
    std::vector<std::vector<std::tuple<int,int>>> parse1(const std::string &filename);
    std::vector<std::vector<std::tuple<int,int>>> parse2(const std::string &filename);
    int mul(int a, int b);
    int solve1(std::vector<std::vector<std::tuple<int,int>>> &program);
    int solve2(std::vector<std::vector<std::tuple<int,int>>> &program);
}

#endif //MULLITOVER_H
