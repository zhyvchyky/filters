cmake_minimum_required(VERSION 3.17)
project(filters)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)
#include_directories(processors)

add_executable(filters
        processors/GaussianBlurProcessor.cpp
        processors/GaussianBlurProcessor.h
        processors/ImageSourceProcessor.cpp
        processors/ImageSourceProcessor.h
        processors/IProcessor.h
        CMakeLists.txt
        Conveyor.cpp
        Conveyor.h
        ConveyorManager.cpp
        ConveyorManager.h
        Filters.cpp
        Filters.h
        Image.cpp
        Image.h
        main.cpp
        Node.cpp
        Node.h
        NodeType.h
        processors/ImageOutputProcessor.cpp
        processors/ImageOutputProcessor.h
        processors/BlackAndWhiteProcessor.cpp
        processors/BlackAndWhiteProcessor.h)
