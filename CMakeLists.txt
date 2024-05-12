cmake_minimum_required(VERSION 3.28)
project(HomeAssignment2_SP2)

set(CMAKE_CXX_STANDARD 11)

add_executable(Demo
        Algorithms.cpp
        Graph.cpp
        Demo.cpp
)

add_executable(Test
        Algorithms.cpp
        Graph.cpp
        Test.cpp
        TestCounter.cpp
)
