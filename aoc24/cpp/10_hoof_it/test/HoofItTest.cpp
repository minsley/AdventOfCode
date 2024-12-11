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
            const std::string filename = "hoof_it_example1.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto input = parse(inputStr);
        }
        TEST_CASE("Example_01") {
            const std::string filename = "hoof_it_example1.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto input = parse(inputStr);
            CHECK(solve1(input) == 31);
        }
        TEST_CASE("Example_02") {
            const std::string filename = "hoof_it_example2.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto input = parse(inputStr);
            CHECK(solve1(input) == 31);
        }
        TEST_CASE("Example_03") {
            const std::string filename = "hoof_it_example3.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto input = parse(inputStr);
            CHECK(solve1(input) == 31);
        }
        TEST_CASE("Example_04") {
            const std::string filename = "hoof_it_example4.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto input = parse(inputStr);
            CHECK(solve1(input) == 31);
        }
    }
}

