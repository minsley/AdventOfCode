//
// Created by mins on 12/2/2024.
//

#include "MullItOver.h"

#include <string>
#include <regex>
#include <vector>

#include "../util/TestHelper.h"


using namespace MullItOver;

int MullItOver::mul(int a, int b) {
    return a * b;
}

std::vector<std::tuple<int,int>> MullItOver::parse1(const std::string &filename) {
    std::vector<std::tuple<int,int>> result;

    std::regex re(R"((mul\((\d+),(\d+)\)))");

    auto fileStr = TestHelper::readFileToString(filename);
    std::regex_token_iterator<std::string::iterator> rend;
    int submatches[] = { 2, 3 };
    std::regex_token_iterator<std::string::iterator> rcur( fileStr.begin(), fileStr.end(), re, submatches );
    while (rcur != rend) {
        std::string aStr = *rcur++;
        std::string bStr = *rcur++;
        std::tuple<int,int> instruction(stoi(aStr), stoi(bStr));
        result.push_back(instruction);
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
