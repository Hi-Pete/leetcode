cmake_minimum_required(VERSION 3.5)
project(Offer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Dynamic_Programming/10.Regular_Expression_Matching.cpp Offer29.cpp Offer30.cpp Offer31.cpp)
add_executable(Offer ${SOURCE_FILES} Dynamic_Programming/10.Regular_Expression_Matching.cpp)