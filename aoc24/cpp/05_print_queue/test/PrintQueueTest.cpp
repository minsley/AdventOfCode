//
// Created by Matt Insley on 12/5/24.
//

#include "../../lib/doctest.h"

#include "../PrintQueue.h"
#include "../../util/TestHelper.h"

TEST_SUITE("05_PrintQueue") {
    TEST_CASE("Example_1") {
        std::string filename = "print_queue_example.txt";
        std::string inputStr = TestHelper::readFileToString(filename);
        auto printQueue = print_queue::parse(inputStr);
        CHECK(print_queue::solve1(printQueue) == 143);
    }

    TEST_CASE("Part_1") {
        SUBCASE("minsfb") {
            const std::string filename = "print_queue_input1_minsfb.txt";
            std::string inputStr = TestHelper::readFileToString(filename);
            auto printQueue = print_queue::parse(inputStr);
            CHECK(print_queue::solve1(printQueue) == 4637);
        }
        SUBCASE("minsley") {
            const std::string filename = "print_queue_input1_minsley.txt";
            std::string inputStr = TestHelper::readFileToString(filename);
            auto printQueue = print_queue::parse(inputStr);
            CHECK(print_queue::solve1(printQueue) == 4790);
        }
    }

    TEST_CASE("Example_2") {
        std::string filename = "print_queue_example.txt";
        std::string inputStr = TestHelper::readFileToString(filename);
        auto printQueue = print_queue::parse(inputStr);
        CHECK(print_queue::solve2(printQueue) == 123);
    }

    TEST_CASE("Part_2") {
        SUBCASE("minsfb") {
            const std::string filename = "print_queue_input1_minsfb.txt";
            std::string inputStr = TestHelper::readFileToString(filename);
            auto printQueue = print_queue::parse(inputStr);
            CHECK(print_queue::solve2(printQueue) == 6370);
        }
        SUBCASE("minsley") {
            const std::string filename = "print_queue_input1_minsley.txt";
            std::string inputStr = TestHelper::readFileToString(filename);
            auto printQueue = print_queue::parse(inputStr);
            CHECK(print_queue::solve2(printQueue) == 6319);
        }
    }
}