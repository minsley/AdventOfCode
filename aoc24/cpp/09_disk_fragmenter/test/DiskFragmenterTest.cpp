//
// Created by Matt Insley on 12/10/24.
//

#include <vector>

#include "../../lib/doctest.h"

#include "../DiskFragmenter.h"
#include "../../util/TestHelper.h"

namespace DiskFragmenter::Test {
    DiskFragmenter::InputSet parse(const std::string &inputStr) {
        DiskFragmenter::InputSet result;
        return result;
    }

    TEST_SUITE("09_DiskFragmenter") {
        TEST_CASE("Parsing") {
            const std::string filename = "disk_fragmenter_example.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto input = parse(inputStr);
        }
        TEST_CASE("Part_1_Examples") {
            SUBCASE("Example") {
                const std::string filename = "disk_fragmenter_example.txt";
                const std::string inputStr = TestHelper::readFileToString(filename);
                auto input = parse(inputStr);
                CHECK(solve1(input) == 31);
            }
        }
    }
}

