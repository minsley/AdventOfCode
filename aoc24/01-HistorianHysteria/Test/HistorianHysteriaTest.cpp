//
// Created by mins on 12/2/2024.
//

#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
#include <bits/fs_fwd.h>
#include <bits/fs_path.h>

#include "../../doctest.h"
#include "../Solution/HistorianHysteria.h"
#include "../../TestHelper.h"

namespace HistorianHysteria {
    std::tuple<std::vector<int>, std::vector<int>> parse(const std::string &filename) {

        std::vector<int> list1;
        std::vector<int> list2;

        std::filesystem::__cxx11::path currentPath = std::filesystem::current_path();
        std::cout << "Current working directory: " << currentPath << std::endl;

        auto fileStr = TestHelper::ReadFileToString(filename);
        for (auto line : TestHelper::tokenize(fileStr, "\r\n")) {
            auto nums = TestHelper::tokenize(line, "   ");
            list1.push_back(std::stoi(nums.front()));
            list2.push_back(std::stoi(nums.back()));
        }

        return {list1, list2};
    }
}

TEST_SUITE("01 HistorianHysteria") {
    TEST_CASE("Example 1") {
        std::string filename = "HistorianHysteriaExample.txt";
        auto [list1, list2] = HistorianHysteria::parse(filename);
        CHECK(HistorianHysteria::solve1(list1, list2) == 11);
    }

    TEST_CASE("Part 1") {
        std::string filename = "HistorianHysteriaInput.txt";
        auto [list1, list2] = HistorianHysteria::parse(filename);
        CHECK(HistorianHysteria::solve1(list1, list2) == 2344935);
    }

    TEST_CASE("Example 2") {
        std::string filename = "HistorianHysteriaExample.txt";
        auto [list1, list2] = HistorianHysteria::parse(filename);
        CHECK(HistorianHysteria::solve2(list1, list2) == 31);
    }

    TEST_CASE("Part 2") {
        std::string filename = "HistorianHysteriaInput.txt";
        auto [list1, list2] = HistorianHysteria::parse(filename);
        CHECK(HistorianHysteria::solve2(list1, list2) == 31);
    }
}