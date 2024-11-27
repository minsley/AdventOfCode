//
// Created by mins on 11/27/2024.
//

#include "TrebuchetTest.h"

#include "../doctest.h"
#include "Trebuchet.h"

TEST_SUITE("01 Trebuchet") {

    TEST_CASE("Example 1") {
        CHECK(Trebuchet::solve1(TrebuchetTest::example1) == 142);
    }

    TEST_CASE("Part 1") {
        CHECK(Trebuchet::solve1(TrebuchetTest::input) == 55017);
    }

    TEST_CASE("Example 2") {
        CHECK(Trebuchet::solve2(TrebuchetTest::example2) == 281);
    }

    TEST_CASE("Part 2") {
        CHECK(Trebuchet::solve2(TrebuchetTest::input) == 53539);
    }

}