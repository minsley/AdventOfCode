//
// Created by mins on 12/2/2024.
//

#include "MullItOver.h"

#include <string>
#include <regex>
#include <vector>

using namespace MullItOver;

int MullItOver::mul(int a, int b) {
    return a * b;
}

std::vector<std::tuple<int,int>> MullItOver::parse1(const std::string &inputStr) {
    std::vector<std::tuple<int,int>> result;

    const std::regex re(R"(mul\((\d{1,3}),(\d{1,3})\))");
    for(auto i = std::sregex_iterator(inputStr.begin(), inputStr.end(), re);
        i != std::sregex_iterator();
        *i++)
    {
        const std::smatch &m = *i;
        if(!m[1].matched || !m[2].matched) continue;

        result.emplace_back(std::stoi(m[1]), std::stoi(m[2]));
    }

    return result;
}

int MullItOver::solve(std::vector<std::tuple<int,int>> &program) {
    int sum = 0;
    for(const auto [a,b] : program) {
        sum += MullItOver::mul(a,b);
    }
    return sum;
}
