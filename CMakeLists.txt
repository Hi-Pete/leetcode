cmake_minimum_required(VERSION 3.6)
project(Offer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Binary-search/875.Koko_Eating_Bananas.cpp Tree/RB-Tree.cpp Binary-search/1011.Capacity_To_Ship_Packages_Within_D_Days.cpp)
add_executable(Offer ${SOURCE_FILES} Binary-search/875.Koko_Eating_Bananas.cpp)