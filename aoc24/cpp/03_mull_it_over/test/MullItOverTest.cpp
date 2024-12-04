//
// Created by mins on 12/2/2024.
//

#include <iostream>
#include <vector>

#include "../../lib/doctest.h"

#include "../MullItOver.h"
#include "../../util/TestHelper.h"

TEST_SUITE("03_MullItOver")
{
    TEST_CASE("Example_1") {
        const std::string filename = "MullItOverExample1.txt";
        auto inputStr = TestHelper::readFileToString(filename);
        auto program = MullItOver::parse1(inputStr);

        SUBCASE("mul(2,4) = 8") {
            auto [a, b] = program[0];
            CHECK(MullItOver::mul(a, b) == 8);
        }

        SUBCASE("mul(5,5) = 25") {
            auto [a, b] = program[1];
            CHECK(MullItOver::mul(a, b) == 25);
        }

        SUBCASE("mul(11,8) = 88") {
            auto [a, b] = program[2];
            CHECK(MullItOver::mul(a, b) == 88);
        }

        SUBCASE("mul(8,5) = 40") {
            auto [a, b] = program[3];
            CHECK(MullItOver::mul(a, b) == 40);
        }

        SUBCASE("Recheck All") {
            std::cout << "mul mul mul mul add" << std::endl;
            CHECK(MullItOver::solve(program) == 161);
        }
    }

    TEST_CASE("Part_1") {
        SUBCASE("minsfb") {
            const std::string filename = "MullItOverInput_minsfb.txt";
            auto inputStr = TestHelper::readFileToString(filename);
            auto program = MullItOver::parse1(inputStr);
            CHECK(MullItOver::solve(program) == 182619815);
        }
        SUBCASE("minsley") {
            const std::string filename = "MullItOverInput_minsley.txt";
            auto inputStr = TestHelper::readFileToString(filename);
            auto program = MullItOver::parse1(inputStr);
            CHECK(MullItOver::solve(program) == 170068701);
        }
    }

    TEST_CASE("Example_2") {
        const std::string filename = "MullItOverExample2.txt";
        auto inputStr = TestHelper::readFileToString(filename);
        auto program = MullItOver::parse2(inputStr);

        SUBCASE("mul(2,4) = 8") {
            auto [a, b] = program[0];
            CHECK(MullItOver::mul(a, b) == 8);
        }

        SUBCASE("mul(8,5) = 40") {
            auto [a, b] = program[1];
            CHECK(MullItOver::mul(a, b) == 40);
        }

        SUBCASE("Recheck All") {
            std::cout << "mul (ignore) (ignore) mul add" << std::endl;
            CHECK(MullItOver::solve(program) == 48);
        }
    }

    TEST_CASE("Extras_2")
    {
        SUBCASE("Newline madness")
        {
            const std::string input = "\nmul(2,4\n)\nmul(8,5)\n";
            auto program = MullItOver::parse2(input);
            CHECK(MullItOver::solve(program) == 40);
        }
        SUBCASE("Closed for good")
        {
            const std::string input = "mul(2,4)don't()mul(5,5)do()mul(11,8)don't()mul(8,5)";
            auto program = MullItOver::parse2(input);
            CHECK(MullItOver::solve(program) == 96);
        }
    }

    TEST_CASE("Part_2") {
        SUBCASE("minsfb") {
            const std::string filename = "MullItOverInput_minsfb.txt";
            auto inputStr = TestHelper::readFileToString(filename);
            auto program = MullItOver::parse2(inputStr);
            CHECK(MullItOver::solve(program) == 80747545);
            // x < 98632444
        }
        SUBCASE("minsley") {
            const std::string filename = "MullItOverInput_minsley.txt";
            auto inputStr = TestHelper::readFileToString(filename);
            auto program = MullItOver::parse2(inputStr);
            CHECK(MullItOver::solve(program) == 78683433);
        }
    }
}