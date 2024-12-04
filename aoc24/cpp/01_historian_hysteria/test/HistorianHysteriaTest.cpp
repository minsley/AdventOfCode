//
// Created by mins on 12/2/2024.
//

#include <fstream>
#include <vector>

#include "../../lib/doctest.h"

#include "../HistorianHysteria.h"
#include "../../util/TestHelper.h"

namespace HistorianHysteria {
    std::tuple<std::vector<int>, std::vector<int>> parse(const std::string &filename) {

        std::vector<int> list1;
        std::vector<int> list2;

        auto fileStr = TestHelper::readFileToString(filename);
        for (const auto &line : TestHelper::tokenize(fileStr, "\n")) {
            auto nums = TestHelper::tokenize(line, "   ");
            list1.push_back(std::stoi(nums.front()));
            list2.push_back(std::stoi(nums.back()));
        }

        return {list1, list2};
    }
}

TEST_SUITE("01_HistorianHysteria") {
    TEST_CASE("Example_1") {
        std::string filename = "HistorianHysteriaExample.txt";
        auto [list1, list2] = HistorianHysteria::parse(filename);
        CHECK(HistorianHysteria::solve1(list1, list2) == 11);
    }

    TEST_CASE("Part_1") {
        SUBCASE("minsfb") {
            const std::string filename = "HistorianHysteriaInput_minsfb.txt";
            auto [list1, list2] = HistorianHysteria::parse(filename);
            CHECK(HistorianHysteria::solve1(list1, list2) == 2344935);
        }
        SUBCASE("minsley") {
            const std::string filename = "HistorianHysteriaInput_minsley.txt";
            auto [list1, list2] = HistorianHysteria::parse(filename);
            CHECK(HistorianHysteria::solve1(list1, list2) == 1579939);
        }
    }

    TEST_CASE("Example_2") {
        std::string filename = "HistorianHysteriaExample.txt";
        auto [list1, list2] = HistorianHysteria::parse(filename);
        CHECK(HistorianHysteria::solve2(list1, list2) == 31);
    }

    TEST_CASE("Part_2") {
        SUBCASE("minsfb") {
            std::string filename = "HistorianHysteriaInput_minsfb.txt";
            auto [list1, list2] = HistorianHysteria::parse(filename);
            CHECK(HistorianHysteria::solve2(list1, list2) == 27647262);
        }
        SUBCASE("minsley") {
            std::string filename = "HistorianHysteriaInput_minsley.txt";
            auto [list1, list2] = HistorianHysteria::parse(filename);
            CHECK(HistorianHysteria::solve2(list1, list2) == 20351745);
        }
    }
}