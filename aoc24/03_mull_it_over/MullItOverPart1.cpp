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

std::vector<std::vector<std::tuple<int,int>>> MullItOver::parse1(const std::string &filename) {
    std::vector<std::vector<std::tuple<int,int>>> result;

    std::regex re(R"((mul\((\d+),(\d+)\)))");

    auto fileStr = TestHelper::readFileToString(filename);
    for (auto line : TestHelper::tokenize(fileStr, "\n")) {
        std::vector<std::tuple<int,int>> program;
        std::regex_token_iterator<std::string::iterator> rend;
        int submatches[] = { 2, 3 };
        std::regex_token_iterator<std::string::iterator> rcur( line.begin(), line.end(), re, submatches );
        while (rcur != rend) {
            std::string aStr = *rcur++;
            std::string bStr = *rcur++;
            std::tuple<int,int> instruction(stoi(aStr), stoi(bStr));
            program.push_back(instruction);
        }
        result.push_back(program);
    }

    return result;
}

int MullItOver::solve1(std::vector<std::vector<std::tuple<int,int>>> &program) {
    int sum = 0;
    for(const auto &instructions : program){
        for(const auto [a,b] : instructions) {
            sum += MullItOver::mul(a,b);
        }
    }
    return sum;
}
