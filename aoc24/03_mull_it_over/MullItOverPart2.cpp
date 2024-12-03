//
// Created by mins on 12/2/2024.
//

#include "MullItOver.h"

#include <string>
#include <regex>
#include <vector>
#include <iostream>

#include "../util/TestHelper.h"

using namespace MullItOver;

/*

*/

std::vector<std::vector<std::tuple<int,int>>> MullItOver::parse2(const std::string &filename) {
    std::vector<std::vector<std::tuple<int,int>>> result;

    std::regex reTrash(R"(don't\(\).*?do\(\))");
    std::regex reMul(R"()");
    int submatches[] = { 2, 3 };

    auto fileStr = TestHelper::readFileToString(filename);
    for (auto line : TestHelper::tokenize(fileStr, "\n")) {
        std::vector<std::tuple<int,int>> program;
        std::regex_token_iterator<std::string::iterator> rend;
        std::regex_token_iterator<std::string::iterator> rcur( line.begin(), line.end(), reTrash, -1 );
        std::vector<std::string> chunks;
        while (rcur != rend) {
            chunks.push_back(*rcur++);
        }

        for(auto chunk : chunks) {
            std::regex_token_iterator<std::string::iterator> send;
            std::regex_token_iterator<std::string::iterator> scur(chunk.begin(), chunk.end(), reMul);
            while(scur != send) {
//                std::string aStr = *scur++;
//                std::string bStr = *scur++;
                std::cout << *scur++ << std::endl;
//                std::tuple<int,int> instruction(stoi(aStr), stoi(bStr));
//                program.push_back(instruction);
            }
        }

        result.push_back(program);
    }

    return result;
}

int MullItOver::solve2(std::vector<std::vector<std::tuple<int,int>>> &program) {
    return -1;
}
