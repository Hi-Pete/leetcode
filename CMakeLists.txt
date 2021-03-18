cmake_minimum_required(VERSION 3.6)
project(Offer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Binary-search/875.Koko_Eating_Bananas.cpp)
add_executable(Offer ${SOURCE_FILES} Binary-search/875.Koko_Eating_Bananas.cpp)