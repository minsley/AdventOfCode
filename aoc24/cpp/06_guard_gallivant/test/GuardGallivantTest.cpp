//
// Created by Matt Insley on 12/6/24.
//

#include "../../lib/doctest.h"

#include "../GuardGallivant.h"
#include "../../util/TestHelper.h"

TEST_SUITE("06_GuardGallivant") {
    TEST_CASE("Example_1") {
        std::string filename = "guard_gallivant_example.txt";
        std::string inputStr = TestHelper::readFileToString(filename);
        auto board = guard_gallivant::parse(inputStr);
        CHECK(guard_gallivant::solve1(board) == 41);
    }

    TEST_CASE("Part_1") {
        SUBCASE("minsfb") {
            const std::string filename = "guard_gallivant_input_minsfb.txt";
            std::string inputStr = TestHelper::readFileToString(filename);
            auto board = guard_gallivant::parse(inputStr);
            CHECK(guard_gallivant::solve1(board) == -1);
        }
        SUBCASE("minsley") {
            const std::string filename = "guard_gallivant_input_minsley.txt";
            std::string inputStr = TestHelper::readFileToString(filename);
            auto board = guard_gallivant::parse(inputStr);
            CHECK(guard_gallivant::solve1(board) == 143);
        }
    }

    TEST_CASE("Example_2") {
        std::string filename = "guard_gallivant_example.txt";
        std::string inputStr = TestHelper::readFileToString(filename);
        auto board = guard_gallivant::parse(inputStr);
        CHECK(guard_gallivant::solve2(board) == -1);
    }

    TEST_CASE("Part_2") {
        SUBCASE("minsfb") {
            const std::string filename = "guard_gallivant_input1_minsfb.txt";
            std::string inputStr = TestHelper::readFileToString(filename);
            auto printQueue = guard_gallivant::parse(inputStr);
            CHECK(guard_gallivant::solve2(printQueue) == -1);
        }
        SUBCASE("minsley") {
            const std::string filename = "guard_gallivant_input1_minsley.txt";
            std::string inputStr = TestHelper::readFileToString(filename);
            auto printQueue = guard_gallivant::parse(inputStr);
            CHECK(guard_gallivant::solve2(printQueue) == -1);
        }
    }
}