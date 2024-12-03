//
// Created by mins on 12/2/2024.
//

#include <algorithm>
#include <fstream>
#include <vector>

#include "../../lib/doctest.h"

#include "../RedNosedReports.h"
#include "../../util/TestHelper.h"

namespace RedNosedReports {
    std::vector<std::vector<int>> parse(const std::string &filename) {

        auto fileStr = TestHelper::readFileToString(filename);

        std::vector<std::vector<int>> result;

        for (const auto line : TestHelper::tokenize(fileStr, "\n")) {
            std::vector<int> report;
            for(const auto entry : TestHelper::tokenize(line, " ")) {
                report.push_back(std::stoi(entry));
            }
            result.push_back(report);
        }

        return result;
    }
}

TEST_SUITE("02_RedNosedReports") {
    TEST_CASE("Example_1") {
        std::string filename = "RedNosedReportsExample.txt";
        auto reports = RedNosedReports::parse(filename);
        CHECK(RedNosedReports::solve1(reports) == 2);
    }

    TEST_CASE("Part_1") {
        const std::string filename = "RedNosedReportsInput.txt";
        auto reports = RedNosedReports::parse(filename);
        CHECK(RedNosedReports::solve1(reports) == 402);
    }

    TEST_CASE("Example_2") {
        std::string filename = "RedNosedReportsExample.txt";
        auto reports = RedNosedReports::parse(filename);
        // CHECK(RedNosedReports::solve2(reports) == 31);
    }

    TEST_CASE("Part_2") {
        std::string filename = "RedNosedReportsInput.txt";
        auto reports = RedNosedReports::parse(filename);
        // CHECK(RedNosedReports::solve2(reports) == 27647262);
    }
}