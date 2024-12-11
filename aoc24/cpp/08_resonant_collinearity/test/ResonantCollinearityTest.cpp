//
// Created by Matt Insley on 12/10/24.
//

#include <vector>

#include "../../lib/doctest.h"

#include "../ResonantCollinearity.h"
#include "../../util/TestHelper.h"

namespace ResonantCollinearity::Test {
    ResonantCollinearity::InputSet parse(const std::string &inputStr) {
        ResonantCollinearity::InputSet result;
        return result;
    }

    TEST_SUITE("08_ResonantCollinearity") {
        TEST_CASE("Parsing") {
            const std::string filename = "resonant_collinearity_example.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto input = parse(inputStr);
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
}
