cmake_minimum_required(VERSION 3.17)
project(filters)

set(CMAKE_CXX_STANDARD 20)

add_executable(filters main.cpp Node.cpp Node.h NodeType.h Image.cpp Image.h processors/IProcessor.h Conveyor.h Conveyor.cpp ConveyorManager.h ConveyorManager.cpp processors/ImageSourceProcessor.cpp processors/ImageSourceProcessor.h)
