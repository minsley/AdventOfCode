//
// Created by mins on 12/2/2024.
//

#include "MullItOver.h"

#include <string>
#include <regex>
#include <vector>

#include "../util/TestHelper.h"

using namespace MullItOver;

/*

*/

std::vector<std::vector<std::tuple<int,int>>> MullItOver::parse2(const std::string &filename) {
    std::vector<std::vector<std::tuple<int,int>>> result;

    std::regex re(R"(don't\(\).*?do\(\)|mul\((\d+),(\d+)\))");
    int submatches[] = { 1, 2 };

    auto fileStr = TestHelper::readFileToString(filename);
    for (auto line : TestHelper::tokenize(fileStr, "\n")) {
        std::vector<std::tuple<int,int>> program;
        std::regex_token_iterator<std::string::iterator> rend;
        std::regex_token_iterator<std::string::iterator> rcur( line.begin(), line.end(), re, submatches );
        while (rcur != rend) {
            std::string aStr = *rcur++;
            if(aStr.empty()) continue;
            std::string bStr = *rcur++;
            program.emplace_back(std::stoi(aStr), std::stoi(bStr));
        }

        result.push_back(program);
    }

    return result;
}
