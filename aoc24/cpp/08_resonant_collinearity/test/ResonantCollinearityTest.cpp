//
// Created by Matt Insley on 12/10/24.
//

#include <vector>
#include <sstream>
#include <regex>

#include "../../lib/doctest.h"

#include "../ResonantCollinearity.h"
#include "../../util/TestHelper.h"

ResonantCollinearity::InputSet parse(const std::string &inputStr) {
    ResonantCollinearity::InputSet result;
    return result;
}

TEST_SUITE("08_ResonantCollinearity") {
    TEST_CASE("Parsing") {
        const std::string filename = "resonant_collinearity_example.txt";
        const std::string inputStr = TestHelper::readFileToString(filename);
        auto input = parse(inputStr);
        CHECK(input.size() == 9);
        CHECK(input[0].left == 190);
        CHECK(input[0].right == std::vector<int>{10, 19});
        CHECK(input[8].left == 292);
        CHECK(input[8].right == std::vector<int>{11, 6, 16, 20});
    }
    TEST_CASE("Part_1_Examples") {
        SUBCASE("Example") {
            const std::string filename = "resonant_collinearity_example.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto input = parse(inputStr);
            CHECK(solve1(input) == 31);
        }
    }
}

