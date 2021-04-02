cmake_minimum_required(VERSION 3.6)
project(Offer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES DFS/BackTracking/79.Word_Search.cpp DFS/200.Number_of_Islands.cpp DFS/BackTracking/417.Pacific_Atlantic_Water_Flow.cpp DFS/Offer13.Moving_Robot.cpp)
add_executable(Offer ${SOURCE_FILES} DFS/BackTracking/79.Word_Search.cpp)