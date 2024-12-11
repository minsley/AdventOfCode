//
// Created by Matt Insley on 12/10/24.
//

#include <vector>
#include <sstream>

#include "../../lib/doctest.h"

#include "../ResonantCollinearity.h"
#include "../../util/TestHelper.h"

namespace ResonantCollinearity::Test {
    ResonantCollinearity::Map parse(const std::string &inputStr) {
        ResonantCollinearity::Map result;

        std::istringstream iss(inputStr);
        std::string line;
        size_t i = 0;
        while (std::getline(iss, line)) {
            if(line.empty()) continue;

            if(line.size()>result.width) {
                result.width = line.size();
            }

            for(size_t j=0; j<line.size(); j++) {
                if(line[j] == '.') continue;

                result.antennae[line[j]].emplace_back(j,i);
            }

            i++;
        }
        result.height = i;

        return result;
    }

    TEST_SUITE("08_ResonantCollinearity") {
        TEST_CASE("Parsing") {
            const std::string filename = "resonant_collinearity_example.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto input = parse(inputStr);
            CHECK(input.height == 12);
            CHECK(input.width == 12);
            CHECK(input.antennae.size() == 2);
            CHECK(input.antennae['A'].size() == 3);
            CHECK(input.antennae['0'].size() == 4);
            CHECK(input.antennae['A'][2].x == 9);
            CHECK(input.antennae['A'][2].y == 9);
            CHECK(input.antennae['0'][0].x == 8);
            CHECK(input.antennae['0'][0].y == 1);
        }
        TEST_CASE("Part_1_Example") {
            const std::string filename = "resonant_collinearity_example.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto input = parse(inputStr);
            CHECK(solve1(input) == 14);
        }
        TEST_CASE("Part_1_minsley") {
            const std::string filename = "resonant_collinearity_part1_minsley.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto input = parse(inputStr);
            CHECK(solve1(input) == 351);
        }
        TEST_CASE("Part_1_minsfb") {
            const std::string filename = "resonant_collinearity_part1_minsfb.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto input = parse(inputStr);
            CHECK(solve1(input) == 313);
        }
        TEST_CASE("Part_2_Example") {
            const std::string filename = "resonant_collinearity_example.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto input = parse(inputStr);
            CHECK(solve2(input) == 34);
        }
        TEST_CASE("Part_2_minsley") {
            const std::string filename = "resonant_collinearity_part1_minsley.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto input = parse(inputStr);
            CHECK(solve2(input) == 1259);
        }
        TEST_CASE("Part_2_minsfb") {
            const std::string filename = "resonant_collinearity_part1_minsfb.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto input = parse(inputStr);
            CHECK(solve2(input) == 1064);
        }
    }
}
