//
// Created by Matt Insley on 12/10/24.
//

#include <vector>
#include <sstream>
#include <regex>

#include "../../lib/doctest.h"

#include "../HoofIt.h"
#include "../../util/TestHelper.h"

namespace HoofIt::Test {
    HoofIt::InputSet parse(const std::string &inputStr) {
        HoofIt::InputSet result;
        return result;
    }

    TEST_SUITE("10_HoofIt") {
        TEST_CASE("Parsing") {
            const std::string filename = "hoff_it_example.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto input = parse(inputStr);
        }
        TEST_CASE("Part_1_Examples") {
            SUBCASE("Example") {
                const std::string filename = "hoff_it_example.txt";
                const std::string inputStr = TestHelper::readFileToString(filename);
                auto input = parse(inputStr);
                CHECK(solve1(input) == 31);
            }
        }
    }
}

