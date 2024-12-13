//
// Created by Matt Insley on 12/10/24.
//

#include <vector>
#include <sstream>

#include "../../lib/doctest.h"

#include "../DiskFragmenter.h"
#include "../../util/TestHelper.h"

namespace DiskFragmenter::Test {
    std::vector<int> parse(const std::string &inputStr) {
        std::vector<int> result;
        std::istringstream iss(inputStr);
        std::string line;
        while (std::getline(iss, line)) {
            if(line.empty()) continue;
            for(char i : line) {
                result.push_back(i - '0');
            }
        }
        return result;
    }

    TEST_SUITE("09_DiskFragmenter") {
        TEST_CASE("Parsing") {
            const std::string filename = "disk_fragmenter_example.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto input = parse(inputStr);
            CHECK(input == std::vector<int>{2,3,3,3,1,3,3,1,2,1,4,1,4,1,3,1,4,0,2});
        }
        TEST_CASE("Example_1") {
            const std::string inputStr = "12345";
            auto input = parse(inputStr);
            CHECK(solve1(input) == 60);
            // 1,2,3,4,5
            // 0,_,_,1,1,1,_,_,_,_,2,2,2,2,2
            // 0,2,2,1,1,1,2,2,2,_,_,_,_,_,_
            // 0*0,1*2,2*2,3*1,4*1,5*1,6*2,7*2,8*2
            // 0,  2,  4,  3,  4,  5,  12, 14, 16
            // 0,  2,  6,  9,  13, 18, 30, 44, 60
            // 60
        }
        TEST_CASE("Example_2") {
            const std::string inputStr = "90909";
            auto input = parse(inputStr);
            CHECK(solve1(input) == 513);
            // 9,0,9,0,9
            // 0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2
            // 0*0,1*2,2*2,3*1,4*1,5*1,6*2,7*2,8*2
            // 0,0,0,0,0,0,0,0,0,9,10,11,12,13,14,15,16,17,36,38,40,42,44,46,48,50,52
            // 0,0,0,0,0,0,0,0,0,9,19,30,42,55,69,84,100,117,153,191,231,273,317,363,411,461,513
            // 513
        }
        TEST_CASE("Example_3") {
            const std::string filename = "disk_fragmenter_example.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto input = parse(inputStr);
            CHECK(solve1(input) == 1928);
            // 2,        3,             3,             3,              1,    3,                3,                1,    2,          1,    4,                      1,    4,          1,3,    1,4,    0,2
            // 0,   0,   _,   _,   _,   1,   1,   1,   _,   _,   _,    2,    _,    _,    _,    3,    3,    3,    _,    4,    4,    _,    5,    5,    5,    5,    _,    6,    6,6,6,_,7,7,7,_,8,8,8,8,9,9
            // 0,   0,   9,   9,   8,   1,   1,   1,   8,   8,   8,    2,    7,    7,    7,    3,    3,    3,    6,    4,    4,    6,    5,    5,    5,    5,    6,    6
            // 0*0, 1*0, 2*9, 3*9, 4*8, 5*1, 6*1, 7*1, 8*8, 9*8, 10*8, 11*2, 12*7, 13*7, 14*7, 15*3, 16*3, 17*3, 18*6, 19*4, 20*4, 21*6, 22*5, 23*5, 24*5, 25*5, 26*6, 27*6
            // 0,   0,   18,  27,  32,  5,   6,   7,   64,  72,  80,   22,   84,   91,   98,   45,   48,   51,   108,  76,   80,   126,  110,  115,  120,  125,  156,  162
            // 0,   0,   18,  45,  77,  82,  88,  95,  159, 231, 311,  333,  417,  508,  606,  651,  699,  750,  858,  934,  1014, 1140, 1250, 1365, 1485, 1610, 1766, 1928
            // 1928
        }
        TEST_CASE("Extra_1") {
            const std::string inputStr = "000123";
            auto input = parse(inputStr);
            CHECK(solve1(input) == 2);
            // 0,0,0,1,2,3
            // _,2,2,_,_,_
            // 2,2,_,_,_,_
            // 0*2,1*2
            // 2
        }
        TEST_CASE("Part1_minsley") {
            const std::string filename = "disk_fragmenter_part1_minsley.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto input = parse(inputStr);
            CHECK(solve1(input) > 200390238);
            // 200390238 < answer
        }
        TEST_CASE("Part1_minsfb") {
            const std::string filename = "disk_fragmenter_part1_minsfb.txt";
            const std::string inputStr = TestHelper::readFileToString(filename);
            auto input = parse(inputStr);
            CHECK(solve1(input) == 200390238);
        }
    }
}

