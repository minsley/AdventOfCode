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
    std::vector<long> parse(const std::string &inputStr) {
        auto result = std::vector<long>();
        for (const auto &c : TestHelper::tokenize(inputStr, " ")) {
            if (c.empty()) continue;
            result.emplace_back(stoi(c));
        }
        return result;
    }

    TEST_SUITE("11_PlutonianPebbles") {
        TEST_CASE("Parsing") {
            const std::string filename = "plutonian_pebbles_example1.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto input = parse(inputStr);
            CHECK(input == std::vector<long>{0, 1, 10, 99, 999});
        }
        TEST_CASE("Example_1") {
            const std::string filename = "plutonian_pebbles_example1.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto input = parse(inputStr);
            CHECK(solve1(input, 1) == 7);
            blink(input);
            CHECK(input == std::vector<long>{1, 2024, 1, 0, 9, 9, 2021976});
        }
        TEST_CASE("Example_2") {
            const std::string filename = "plutonian_pebbles_example2.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto input = parse(inputStr);

            std::vector<long> workingCopy;
            std::ranges::copy(input, std::back_inserter(workingCopy));
            CHECK(workingCopy == std::vector<long>{125, 17});
            blink(workingCopy);
            CHECK(workingCopy == std::vector<long>{253000, 1, 7});
            blink(workingCopy);
            CHECK(workingCopy == std::vector<long>{253, 0, 2024, 14168});
            blink(workingCopy);
            CHECK(workingCopy == std::vector<long>{512072, 1, 20, 24, 28676032});

            CHECK(solve1(input, 6) == 22);
            CHECK(solve1(input, 25) == 55312);
        }
        TEST_CASE("Part1_minsley") {
            const std::string filename = "plutonian_pebbles_part1_minsley.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto input = parse(inputStr);
            CHECK(solve1(input, 25) == -1);
        }
        TEST_CASE("Part1_minsfb") {
            const std::string filename = "plutonian_pebbles_part1_minsfb.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto input = parse(inputStr);
            CHECK(solve1(input, 25) == 211306);
        }
    }
}

