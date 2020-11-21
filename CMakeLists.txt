cmake_minimum_required(VERSION 3.17)
project(filters)

set(CMAKE_CXX_STANDARD 20)

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
        processors/IProcessor.h
        processors/ImageSourceProcessor.cpp 
        processors/ImageSourceProcessor.h
        main.cpp
        Node.cpp
        Node.h
        NodeType.h)