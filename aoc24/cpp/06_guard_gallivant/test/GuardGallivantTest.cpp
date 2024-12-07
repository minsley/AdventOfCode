//
// Created by Matt Insley on 12/6/24.
//

#include "../../lib/doctest.h"

#include "../GuardGallivant.h"
#include "../../util/TestHelper.h"

bool debug = false;

TEST_SUITE("06_GuardGallivant") {
    TEST_CASE("Part_1_Examples") {
        SUBCASE("Example_1") {
            const std::string filename = "guard_gallivant_example.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto board = guard_gallivant::parse(inputStr);
            CHECK(guard_gallivant::solve1(board, debug) == 41);
        }
        SUBCASE("Extra_1_Triple_Bounce") {
            std::string input;
            input += "...\n";
            input += ".#.\n";
            input += "..#\n";
            input += "...\n";
            input += ".^.\n";
            input += ".#.\n";

            auto board = guard_gallivant::parse(input);
            CHECK(guard_gallivant::solve1(board, debug) == 4);
        }
        SUBCASE("Extra_2_Infinite_Loop") {
            std::string input;
            input += "...\n";
            input += ".#.\n";
            input += "..#\n";
            input += "...\n";
            input += "#^.\n";
            input += ".#.\n";

            auto board = guard_gallivant::parse(input);
            CHECK(guard_gallivant::solve1(board, debug) == 3);
        }
        SUBCASE("Extra_3_Backtrack") {
            std::string input;
            input += "###\n";
            input += "#.#\n";
            input += "#.#\n";
            input += "#^#\n";

            auto board = guard_gallivant::parse(input);
            CHECK(guard_gallivant::solve1(board, debug) == 3);
        }
        SUBCASE("Extra_4_Box") {
            std::string input;
            input += "########\n";
            input += "#......#\n";
            input += "...^...#\n";
            input += "########\n";

            auto board = guard_gallivant::parse(input);
            CHECK(guard_gallivant::solve1(board, debug) == 11);
        }
    }

    TEST_CASE("Part_1_Actual") {
        SUBCASE("minsfb") {
            const std::string filename = "guard_gallivant_input_minsfb.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto board = guard_gallivant::parse(inputStr);
            CHECK(guard_gallivant::solve1(board, debug) > 4818);
            // 4818 < answer
        }
        SUBCASE("minsley") {
            const std::string filename = "guard_gallivant_input_minsley.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto board = guard_gallivant::parse(inputStr);
            CHECK(guard_gallivant::solve1(board, debug) == 4696);
        }
    }

    TEST_CASE("Part_2_Examples") {
        SUBCASE("Example") {
            const std::string filename = "guard_gallivant_example.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto board = guard_gallivant::parse(inputStr);
            CHECK(guard_gallivant::solve2(board, debug) == 6);
        }
        SUBCASE("06_2_Extra_1_Backtrack") {
            std::string input;
            input += "###\n";
            input += "#.#\n";
            input += "#.#\n";
            input += "#^#\n";

            auto board = guard_gallivant::parse(input);
            CHECK(guard_gallivant::solve2(board, debug) == 0);
        }
        SUBCASE("06_2_Extra_2") {
            std::string input;
            input += "....\n";
            input += "#..#\n";
            input += ".^#.\n";

            auto board = guard_gallivant::parse(input);
            CHECK(guard_gallivant::solve2(board, debug) == 1);
        }
        SUBCASE("06_2_Extra_3") {
            std::string input;
            input += "########\n";
            input += "#......#\n";
            input += "...^...#\n";
            input += "########\n";

            auto board = guard_gallivant::parse(input);
            CHECK(guard_gallivant::solve2(board, debug) == 6);
        }
    }

    TEST_CASE("Part_2_Actual") {
        SUBCASE("minsfb") {
            const std::string filename = "guard_gallivant_input1_minsfb.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto printQueue = guard_gallivant::parse(inputStr);
            CHECK(guard_gallivant::solve2(printQueue, debug) == -1);
        }
        SUBCASE("minsley") {
            const std::string filename = "guard_gallivant_input1_minsley.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto printQueue = guard_gallivant::parse(inputStr);
            CHECK(guard_gallivant::solve2(printQueue, debug) == -1);
        }
    }
}