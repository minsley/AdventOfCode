cmake_minimum_required(VERSION 3.28)
project(aoc24)

set(CMAKE_CXX_STANDARD 17)

add_executable(aoc24
        main.cpp
        doctest.h
        01-HistorianHysteria/Solution/HistorianHysteria.h
        01-HistorianHysteria/Solution/HistorianHysteriaPart1.cpp
        01-HistorianHysteria/Solution/HistorianHysteriaPart2.cpp
        01-HistorianHysteria/Test/HistorianHysteriaTest.cpp
        TestHelper.cpp
        TestHelper.h)

file(GLOB MY_FILES "${CMAKE_CURRENT_SOURCE_DIR}/01-HistorianHysteria/Input/*.txt")
file(COPY ${MY_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
