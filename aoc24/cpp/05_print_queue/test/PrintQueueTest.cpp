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
        CHECK(print_queue::solve(printQueue) == 143);
    }

    TEST_CASE("Part_1") {
//        SUBCASE("minsfb") {
//            const std::string filename = "print_queue_input1_minsfb.txt";
//            std::string inputStr = TestHelper::readFileToString(filename);
//            auto printQueue = print_queue::parse(filename);
//            CHECK(print_queue::solve(printQueue) == 143);
//        }
        SUBCASE("minsley") {
            const std::string filename = "print_queue_input1_minsley.txt";
            std::string inputStr = TestHelper::readFileToString(filename);
            auto printQueue = print_queue::parse(inputStr);
            CHECK(print_queue::solve(printQueue) == 4790);
        }
    }
}