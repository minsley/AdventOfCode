//
// Created by mins on 11/27/2024.
//

#include "CubeConundrumTest.h"

#include "CubeConundrum.h"
#include "../doctest.h"

TEST_SUITE("02 Cube Conundrum") {

    TEST_CASE("Example 1") {
        CHECK(CubeConundrum::solve1(CubeConundrumTest::example1) == 8);
    }

    TEST_CASE("Part 1") {
        CHECK(CubeConundrum::solve1(CubeConundrumTest::input) == 55017);
    }

    TEST_CASE("Example 2") {

        CHECK(CubeConundrum::solve2(CubeConundrumTest::example2) == 281);
    }

    TEST_CASE("Part 2") {
        CHECK(CubeConundrum::solve2(CubeConundrumTest::input) == 53539);
    }

}