cmake_minimum_required(VERSION 3.5)
project(Offer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Dynamic_Programming/300.Longest_Increasing_Subsequence.cpp)
add_executable(Offer ${SOURCE_FILES} Dynamic_Programming/300.Longest_Increasing_Subsequence.cpp)