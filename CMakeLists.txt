cmake_minimum_required(VERSION 3.17)
project(filters)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)
#include_directories(processors)

add_executable(filters
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
        NodeType.h
        utilities/applyVectorTransform.h
        utilities/applyVectorTransform.cpp
        nodes/NodeInput.cpp
        nodes/NodeInput.h
        nodes/INode.h
        nodes/NodeOutput.cpp
        nodes/NodeOutput.h
        nodes/GaussianBlurNode.cpp
        nodes/GaussianBlurNode.h
        nodes/BlackAndWhiteNode.h
        nodes/BlackAndWhiteNode.cpp
        nodes/ColorGeneratorNode.h
        nodes/ColorGeneratorNode.cpp
        nodes/MedianNode.h
        nodes/MedianNode.cpp
        nodes/CombineNode.h
        nodes/CombineNode.cpp
        nodes/GaussianNoiseNode.h
        nodes/GaussianNoiseNode.cpp nodes/EdgeDetectionNode.cpp nodes/EdgeDetectionNode.h nodes/NegativeNode.cpp nodes/NegativeNode.h)