//
// Created by Matt Insley on 12/11/24.
//

#include <vector>
#include <sstream>
#include <regex>

#include "../../lib/doctest.h"

#include "../PlutonianPebbles.h"
#include "../../util/TestHelper.h"

namespace PlutonianPebbles::Test {
    std::vector<int> parse(const std::string &inputStr) {
        return {};
    }

    TEST_SUITE("11_PlutonianPebbles") {
        TEST_CASE("Parsing") {
            const std::string filename = "plutonian_pebbles_example1.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto input = parse(inputStr);
        }
        TEST_CASE("Example_1") {
            const std::string filename = "plutonian_pebbles_example1.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto input = parse(inputStr);
            CHECK(solve1(input) == 31);
        }
        TEST_CASE("Example_2") {
            const std::string filename = "plutonian_pebbles_example2.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto input = parse(inputStr);
            CHECK(solve1(input) == 31);
        }
    }
}

