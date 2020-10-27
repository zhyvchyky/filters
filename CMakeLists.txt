cmake_minimum_required(VERSION 3.17)
project(filters)

set(CMAKE_CXX_STANDARD 14)

add_executable(filters main.cpp Node.cpp Node.h NodeType.h Image.cpp Image.h IProcessor.h)
