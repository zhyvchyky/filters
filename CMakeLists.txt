cmake_minimum_required(VERSION 3.17)
project(filters)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

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
        nodes/ANode.h
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
        nodes/GaussianNoiseNode.cpp nodes/EdgeDetectionNode.cpp nodes/EdgeDetectionNode.h nodes/NegativeNode.cpp nodes/NegativeNode.h utilities/IdGenerator.cpp utilities/IdGenerator.h command/ICommand.h command/CreateNodeCommand.cpp command/CreateNodeCommand.h cards/NodeInputCard.cpp cards/NodeInputCard.h IObserver.h ISubject.h cards/GaussianBlurCard.cpp cards/GaussianBlurCard.h utilities/CustomStack.cpp utilities/CustomStack.h)
