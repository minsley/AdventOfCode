cmake_minimum_required(VERSION 3.28)
project(aoc23)

set(CMAKE_CXX_STANDARD 17)

add_executable(aoc23 main.cpp
        doctest.h
        01-Trebuchet/TrebuchetTest.cpp
        01-Trebuchet/Trebuchet.cpp
        01-Trebuchet/Trebuchet.h
        02-CubeConundrum/CubeConundrum.cpp
        02-CubeConundrum/CubeConundrum.h
        02-CubeConundrum/CubeConundrumTest.cpp
)
