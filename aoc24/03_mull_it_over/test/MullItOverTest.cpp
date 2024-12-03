//
// Created by mins on 12/2/2024.
//

#include <iostream>
#include <vector>

#include "../../lib/doctest.h"

#include "../MullItOver.h"

TEST_SUITE("03_MullItOver") {
    TEST_CASE("Example_1") {
        std::string filename = "MullItOverExample.txt";
        auto program = MullItOver::parse1(filename);
        auto muls = program[0];

        SUBCASE("mul(2,4) = 8") {
            auto [a, b] = muls[0];
            CHECK(MullItOver::mul(a, b) == 8);
        }

        SUBCASE("mul(5,5) = 25") {
            auto [a, b] = muls[1];
            CHECK(MullItOver::mul(a, b) == 25);
        }

        SUBCASE("mul(11,8) = 88") {
            auto [a, b] = muls[2];
            CHECK(MullItOver::mul(a, b) == 88);
        }

        SUBCASE("mul(8,5) = 40") {
            auto [a, b] = muls[3];
            CHECK(MullItOver::mul(a, b) == 40);
        }

        SUBCASE("Recheck All") {
            std::cout << "mul mul mul mul add" << std::endl;
            CHECK(MullItOver::solve1(program) == 161);
        }
    }

    TEST_CASE("Part_1") {
        SUBCASE("minsfb") {
            const std::string filename = "MullItOverInput_minsfb.txt";
            auto muls = MullItOver::parse1(filename);
            CHECK(MullItOver::solve1(muls) == -1);
        }
        SUBCASE("minsley") {
            const std::string filename = "MullItOverInput_minsley.txt";
            auto muls = MullItOver::parse1(filename);
            CHECK(MullItOver::solve1(muls) == 170068701);
        }
    }

    TEST_CASE("Example_2") {
        std::string filename = "MullItOverExample.txt";
        auto program = MullItOver::parse2(filename);
        auto muls = program[0];

        SUBCASE("mul(2,4) = 8") {
            auto [a, b] = muls[0];
            CHECK(MullItOver::mul(a, b) == 1);
        }

        SUBCASE("mul(5,5) = 25") {
            auto [a, b] = muls[1];
            CHECK(MullItOver::mul(a, b) == -1);
        }

        SUBCASE("mul(11,8) = 88") {
            auto [a, b] = muls[2];
            CHECK(MullItOver::mul(a, b) == -1);
        }

        SUBCASE("mul(8,5) = 40") {
            auto [a, b] = muls[3];
            CHECK(MullItOver::mul(a, b) == -1);
        }

        SUBCASE("Recheck All") {
            std::cout << "mul mul mul mul add" << std::endl;
            CHECK(MullItOver::solve2(program) == -1);
        }
    }

    TEST_CASE("Part_2") {
        SUBCASE("minsfb") {
            const std::string filename = "MullItOverInput_minsfb.txt";
            auto muls = MullItOver::parse2(filename);
            CHECK(MullItOver::solve2(muls) == -1);
        }
        SUBCASE("minsley") {
            const std::string filename = "MullItOverInput_minsley.txt";
            auto muls = MullItOver::parse2(filename);
            CHECK(MullItOver::solve2(muls) == -1);
        }
    }
}