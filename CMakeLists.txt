cmake_minimum_required(VERSION 3.5)
project(Offer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Sort/Sort.cpp Binary-search/binarySearch.cpp)
add_executable(Offer ${SOURCE_FILES} Sort/Sort.cpp)
