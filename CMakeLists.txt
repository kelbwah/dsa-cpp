cmake_minimum_required(VERSION 3.29)
project(dsa)

set(CMAKE_CXX_STANDARD 17)

add_executable(dsa src/main.cpp
        src/LinkedList/LinkedList.hpp
        src/LinkedList/LinkedList.cpp
)
