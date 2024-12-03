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

std::vector<std::tuple<int,int>> MullItOver::parse2(const std::string &filename) {
    std::vector<std::tuple<int,int>> result;

    std::regex re(R"(don't\(\).*?do\(\)|mul\((\d+),(\d+)\))", std::regex_constants::_S_multiline);

    auto fileStr = TestHelper::readFileToString(filename);
    for(auto i = std::sregex_iterator(fileStr.begin(), fileStr.end(), re);
        i != std::sregex_iterator();
        *i++)
    {
        const std::smatch &m = *i;
        if(!m[1].matched || !m[2].matched) continue;

        std::string aStr = m[1];
        std::string bStr = m[2];
        result.emplace_back(std::stoi(aStr), std::stoi(bStr));
    }

    return result;
}
