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
Match [don't()...do()] blocks and mul(num,num) blocks that are outside of them, capture the number pairs.
*/

std::vector<std::tuple<int,int>> MullItOver::parse2(const std::string &filename) {
    std::vector<std::tuple<int,int>> result;

    auto fileStr = TestHelper::readFileToString(filename);
    const std::regex re(R"(don't\(\)(?:.|\n)*?do\(\)|mul\((\d+),(\d+)\))");
    for(auto i = std::sregex_iterator(fileStr.begin(), fileStr.end(), re);
        i != std::sregex_iterator();
        *i++)
    {
        const std::smatch &m = *i;
        if(!m[1].matched || !m[2].matched) continue;

        result.emplace_back(std::stoi(m[1]), std::stoi(m[2]));
    }

    return result;
}
