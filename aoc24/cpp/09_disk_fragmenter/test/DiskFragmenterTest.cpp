//
// Created by Matt Insley on 12/10/24.
//

#include <vector>
#include <sstream>

#include "../../lib/doctest.h"

#include "../DiskFragmenter.h"
#include "../../util/TestHelper.h"

namespace DiskFragmenter::Test {
    std::vector<int> parse(const std::string &inputStr) {
        std::vector<int> result;
        std::istringstream iss(inputStr);
        std::string line;
        while (std::getline(iss, line)) {
            if(line.empty()) continue;
            for(char i : line) {
                result.push_back(i - '0');
            }
        }
        return result;
    }

    TEST_SUITE("09_DiskFragmenter") {
        TEST_CASE("Parsing") {
            const std::string filename = "disk_fragmenter_example.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto input = parse(inputStr);
            CHECK(input == std::vector<int>{2,3,3,3,1,3,3,1,2,1,4,1,4,1,3,1,4,0,2});
        }
        TEST_CASE("Example_1") {
            const std::string inputStr = "12345";
            auto input = parse(inputStr);
            CHECK(solve1(input) == 60);
        }
        TEST_CASE("Example_2") {
            const std::string filename = "disk_fragmenter_example.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto input = parse(inputStr);
            CHECK(solve1(input) == 1928);
        }
        TEST_CASE("Part1_minsley") {
            const std::string filename = "disk_fragmenter_part1_minslet.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto input = parse(inputStr);
            CHECK(solve1(input) == -1);
        }
        TEST_CASE("Example_2") {
            const std::string filename = "disk_fragmenter_part1_minsfb.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto input = parse(inputStr);
            CHECK(solve1(input) == -1);
        }
    }
}

