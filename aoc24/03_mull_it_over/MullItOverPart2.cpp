//
// Created by mins on 12/2/2024.
//

#include "MullItOver.h"

#include <iostream>
#include <string>
#include <regex>
#include <vector>

#include "../util/TestHelper.h"

using namespace MullItOver;

/*

*/

std::vector<std::vector<std::tuple<int,int>>> MullItOver::parse2(const std::string &filename) {
    std::vector<std::vector<std::tuple<int,int>>> result;

    std::regex re(R"(don't\(\).*?do\(\)|mul\((\d+),(\d+)\))", std::regex_constants::_S_multiline);
    int submatches[] = { 1, 2 };

    auto fileStr = TestHelper::readFileToString(filename);
    // for (auto line : TestHelper::tokenize(fileStr, "\n")) {
        std::vector<std::tuple<int,int>> program;
        // std::sregex_iterator rend;
        // std::sregex_iterator rcur(line.begin(), line.end(), re);
        // while(rcur != rend)
        // {
        //     std::smatch match = *rcur++;
        //     if(!match[1].matched || !match[2].matched) continue;
        //     std::string aStr = match[1];
        //     std::string bStr = match[2];
        //     program.emplace_back(std::stoi(aStr), std::stoi(bStr));
        // }

        for(auto i = std::sregex_iterator(fileStr.begin(), fileStr.end(), re);
            i != std::sregex_iterator();
            *i++)
        {
            const std::smatch &m = *i;
            if(!m[1].matched || !m[2].matched) continue;

            std::string aStr = m[1];
            std::string bStr = m[2];
            program.emplace_back(std::stoi(aStr), std::stoi(bStr));
        }

        result.push_back(program);
    // }

    return result;
}
