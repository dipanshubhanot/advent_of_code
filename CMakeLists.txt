cmake_minimum_required(VERSION 3.15)
SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED True)
SET (CMAKE_CXX_FLAGS "-g")
project(AdventOfCode)


add_executable(AdventOfCode2022
    src/2022/main.cpp
    src/2022/day1.cpp
    src/2022/day2.cpp
)

include_directories("${CMAKE_SOURCE_DIR}/include")
