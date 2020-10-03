cmake_minimum_required(VERSION 3.15)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 14)

include_directories(./include)

add_executable(TicTacToe main.cpp include/TicTacToe.h src/TicTacToe.cpp)