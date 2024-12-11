//
// Created by Matt Insley on 12/7/24.
//

#include <vector>
#include <sstream>
#include <regex>
#include <iostream>

#include "../../lib/doctest.h"

#include "../BridgeRepair.h"
#include "../../util/TestHelper.h"

namespace BridgeRepair::Test {
    BridgeRepair::InputSet parse(const std::string &inputStr) {
        BridgeRepair::InputSet result;

        std::istringstream iss(inputStr);
        std::string line;
        while (std::getline(iss, line)) {
            if(line.empty()) continue;

            BridgeRepair::Equation eq;
            size_t iDelim = line.find(':');
            eq.left = std::stol(line.substr(0, iDelim));

            for (auto &token : TestHelper::tokenize(line.substr(iDelim+1), " ")) {
                if (token.empty()) continue;
                eq.right.push_back(std::stoi(token));
            }

            result.push_back(eq);
        }

        return result;
    }

    TEST_SUITE("07_BridgeRepair") {
        TEST_CASE("Parsing") {
            const std::string filename = "bridge_repair_example.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto input = parse(inputStr);
            CHECK(input.size() == 9);
            CHECK(input[0].left == 190);
            CHECK(input[0].right == std::vector<long>{10, 19});
            CHECK(input[8].left == 292);
            CHECK(input[8].right == std::vector<long>{11, 6, 16, 20});
        }
        TEST_CASE("Part_1_Example") {
            const std::string filename = "bridge_repair_example.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto input = parse(inputStr);
            CHECK(solve1(input) == 3749);
        }
        TEST_CASE("Part_1_minsley") {
            const std::string filename = "bridge_repair_part1_minsley.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto input = parse(inputStr);
            CHECK(solve1(input) == 7885693428401);
        }
        TEST_CASE("Part_1_minsfb") {
            const std::string filename = "bridge_repair_part1_minsfb.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto input = parse(inputStr);
            CHECK(solve1(input) == 14711933466277);
        }
        TEST_CASE("Part_2_Example") {
            const std::string filename = "bridge_repair_example.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto input = parse(inputStr);
            CHECK(solve2(input) == 11387);
        }
        TEST_CASE("Part_2_minsley") {
            const std::string filename = "bridge_repair_part1_minsley.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto input = parse(inputStr);
            CHECK(solve2(input) == 348360680516005);
        }
        TEST_CASE("Part_2_minsfb") {
            const std::string filename = "bridge_repair_part1_minsfb.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto input = parse(inputStr);
            CHECK(solve2(input) == 286580387663654);
        }
    }
}
