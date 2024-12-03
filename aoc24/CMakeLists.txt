cmake_minimum_required(VERSION 3.28)
project(aoc24)

set(CMAKE_CXX_STANDARD 17)

add_executable(aoc24
        main.cpp
        lib/doctest.h
        01-HistorianHysteria/HistorianHysteria.h
        01-HistorianHysteria/HistorianHysteriaPart1.cpp
        01-HistorianHysteria/HistorianHysteriaPart2.cpp
        01-HistorianHysteria/Test/HistorianHysteriaTest.cpp
        util/TestHelper.cpp
        util/TestHelper.h)

file(GLOB INPUT_FILES ${CMAKE_CURRENT_SOURCE_DIR}/**/Input/*)
file(COPY ${INPUT_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
