cmake_minimum_required(VERSION 3.17)
project(filters)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(filters
        Conveyor.cpp
        Conveyor.h
        ConveyorManager.cpp
        ConveyorManager.h
        Filters.cpp
        Filters.h
        Image.cpp
        Image.h
        IProcessor.h
        main.cpp
        Node.cpp
        Node.h
        NodeType.h)
