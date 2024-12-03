//
// Created by mins on 12/2/2024.
//

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

#include "../../lib/doctest.h"

#include "../RedNosedReports.h"
#include "../../util/TestHelper.h"

namespace RedNosedReports
{
    std::vector<std::vector<int>> parse(const std::string &filename) {
        std::vector<std::vector<int>> result;

        auto fileStr = TestHelper::readFileToString(filename);
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

        SUBCASE("7 6 4 2 1: True") {
            std::cout << "7 6 4 2 1: Safe because the levels are all decreasing by 1 or 2." << std::endl;
            CHECK(RedNosedReports::isValidReport1(reports[0]) == true);
        }

        SUBCASE("1 2 7 8 9: False") {
            std::cout << "1 2 7 8 9: Unsafe because 2 7 is an increase of 5." << std::endl;
            CHECK(RedNosedReports::isValidReport1(reports[1]) == false);
        }

        SUBCASE("9 7 6 2 1: False") {
            std::cout << "9 7 6 2 1: Unsafe because 6 2 is a decrease of 4." << std::endl;
            CHECK(RedNosedReports::isValidReport1(reports[2]) == false);
        }

        SUBCASE("1 3 2 4 5: False") {
            std::cout << "1 3 2 4 5: Unsafe because 1 3 is increasing but 3 2 is decreasing." << std::endl;
            CHECK(RedNosedReports::isValidReport1(reports[3]) == false);
        }

        SUBCASE("8 6 4 4 1: False") {
            std::cout << "8 6 4 4 1: Unsafe because 4 4 is neither an increase or a decrease." << std::endl;
            CHECK(RedNosedReports::isValidReport1(reports[4]) == false);
        }

        SUBCASE("1 3 6 7 9: True") {
            std::cout << "1 3 6 7 9: Safe because the levels are all increasing by 1, 2, or 3." << std::endl;
            CHECK(RedNosedReports::isValidReport1(reports[5]) == true);
        }

        SUBCASE("Recheck All Reports") {
            std::cout << "2/6 reports are valid." << std::endl;
            CHECK(RedNosedReports::solve1(reports) == 2);
        }
    }

    TEST_CASE("Part_1") {
        SUBCASE("minsfb") {
            const std::string filename = "RedNosedReportsInput_minsfb.txt";
            auto reports = RedNosedReports::parse(filename);
            CHECK(RedNosedReports::solve1(reports) == 402);
        }
        SUBCASE("minsley") {
            const std::string filename = "RedNosedReportsInput_minsley.txt";
            auto reports = RedNosedReports::parse(filename);
            CHECK(RedNosedReports::solve1(reports) == 242);
        }
    }

    TEST_CASE("Example_2") {
        std::string filename = "RedNosedReportsExample.txt";
        auto reports = RedNosedReports::parse(filename);

        SUBCASE("7 6 4 2 1: Safe without removing any level") {
            CHECK(RedNosedReports::isValidReport2(reports[0]) == true);
        }

        SUBCASE("1 2 7 8 9: Unsafe regardless of which level is removed") {
            CHECK(RedNosedReports::isValidReport2(reports[1]) == false);
        }

        SUBCASE("9 7 6 2 1: Unsafe regardless of which level is removed") {
            CHECK(RedNosedReports::isValidReport2(reports[2]) == false);
        }

        SUBCASE("1 3 2 4 5: Safe by removing the second level, 3") {
            CHECK(RedNosedReports::isValidReport2(reports[3]) == true);
        }

        SUBCASE("8 6 4 4 1: Safe by removing the third level, 4") {
            CHECK(RedNosedReports::isValidReport2(reports[4]) == true);
        }

        SUBCASE("1 3 6 7 9: Safe without removing any level") {
            CHECK(RedNosedReports::isValidReport2(reports[5]) == true);
        }

        SUBCASE("Recheck All Reports") {
            CHECK(RedNosedReports::solve2(reports) == 4);
        }
    }

    TEST_CASE("Extras_2") {
        SUBCASE("57 56 57 59 60 63 64 65: Safe to remove first 57") {
            std::vector<int> report = {57, 56, 57, 59, 60, 63, 64, 65};
            CHECK(RedNosedReports::isValidReport2(report) == true);
        }
        SUBCASE("63 66 68 70 73 77 76: Safe to remove 77") {
            std::vector<int> report = {63, 66, 68, 70, 73, 77, 76};
            CHECK(RedNosedReports::isValidReport2(report) == true);
        }
    }

    TEST_CASE("Part_2") {
        SUBCASE("minsfb") {
            const std::string filename = "RedNosedReportsInput_minsfb.txt";
            auto reports = RedNosedReports::parse(filename);
            CHECK(RedNosedReports::solve2(reports) == -1);
        }
        SUBCASE("minsley") {
            const std::string filename = "RedNosedReportsInput_minsley.txt";
            auto reports = RedNosedReports::parse(filename);
            CHECK(RedNosedReports::solve2(reports) == 311);
        }
    }
}