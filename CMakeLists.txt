cmake_minimum_required(VERSION 3.7)

project(DFA)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)


include_directories(src/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin/)


add_executable(
    DFA
    src/main.cpp
)