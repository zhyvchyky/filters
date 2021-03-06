cmake_minimum_required(VERSION 3.17)
project(filters)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 20)

include_directories(.)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)


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
        nodes/GaussianNoiseNode.cpp
        nodes/EdgeDetectionNode.cpp
        nodes/EdgeDetectionNode.h
        nodes/NegativeNode.cpp
        nodes/NegativeNode.h
        utilities/IdGenerator.cpp
        utilities/IdGenerator.h
        command/ICommand.h
        command/createCommands/CreateNodeCommand.cpp
        command/createCommands/CreateNodeCommand.h
        gui/cards/NodeInputCard.cpp
        gui/cards/NodeInputCard.h
        IObserver.h
        ISubject.h
        gui/cards/GaussianBlurCard.cpp
        gui/cards/GaussianBlurCard.h
        utilities/CustomStack.h
        command/createCommands/CreateConveyorCommand.cpp
        command/createCommands/CreateConveyorCommand.h
        command/createCommands/CreateConnectionCommand.cpp
        command/createCommands/CreateConnectionCommand.h
        command/deleteCommands/DeleteConnectionCommand.cpp
        command/deleteCommands/DeleteConnectionCommand.h
        command/deleteCommands/DeleteConveyorCommand.cpp
        command/deleteCommands/DeleteConveyorCommand.h
        command/deleteCommands/DeleteNodeCommand.cpp
        command/deleteCommands/DeleteNodeCommand.h
        command/ProcessCommand.cpp
        command/ProcessCommand.h
        command/setCommands/SetColorGeneratorCommand.cpp
        command/setCommands/SetColorGeneratorCommand.h
        command/setCommands/SetGaussianBlurCommand.cpp
        command/setCommands/SetGaussianBlurCommand.h
        command/setCommands/SetGaussianNoiseCommand.cpp
        command/setCommands/SetGaussianNoiseCommand.h
        command/setCommands/SetMedianCommand.cpp
        command/setCommands/SetMedianCommand.h
        command/setCommands/SetNodeInputCommand.cpp
        command/setCommands/SetNodeInputCommand.h
        command/setCommands/SetNodeOutputCommand.cpp
        command/setCommands/SetNodeOutputCommand.h
        gui/cards/ColorGeneratorCard.cpp
        gui/cards/ColorGeneratorCard.h
        gui/cards/GaussianNoiseCard.cpp
        gui/cards/GaussianNoiseCard.h
        gui/cards/MedianCard.cpp
        gui/cards/MedianCard.h
        gui/cards/NodeOutputCard.cpp
        gui/cards/NodeOutputCard.h
        command/attachCommands/AAttachCommand.h
        command/attachCommands/AttachGaussianBlurCommand.cpp
        command/attachCommands/AttachGaussianBlurCommand.h
        command/attachCommands/AttachInputCommand.cpp
        command/attachCommands/AttachInputCommand.h
        command/attachCommands/AttachOutputCommand.cpp
        command/attachCommands/AttachOutputCommand.h
        command/attachCommands/AttachMedianCommand.cpp
        command/attachCommands/AttachMedianCommand.h
        command/attachCommands/AttachGaussianNoiseCommand.cpp
        command/attachCommands/AttachGaussianNoiseCommand.h
        command/attachCommands/AttachColorGeneratorCommand.cpp
        command/attachCommands/AttachColorGeneratorCommand.h
        command/deattach/DeattachColorGeneratorCommand.cpp
        command/deattach/DeattachColorGeneratorCommand.h
        command/deattach/DeattachGaussianBlurCommand.cpp
        command/deattach/DeattachGaussianBlurCommand.h
        command/deattach/DeattachGaussianNoiseCommand.cpp
        command/deattach/DeattachGaussianNoiseCommand.h
        command/deattach/DeattachInputCommand.cpp
        command/deattach/DeattachInputCommand.h
        command/deattach/DeattachMedianCommand.cpp
        command/deattach/DeattachMedianCommand.h
        command/deattach/DeattachOutputCommand.cpp
        command/deattach/DeattachOutputCommand.h
        gui/cards/ConveyorCard.cpp
        gui/cards/ConveyorCard.h
        gui/cards/ConveyorManagerCard.cpp
        gui/cards/ConveyorManagerCard.h
        command/attachCommands/AttachConveyorCommand.cpp
        command/attachCommands/AttachConveyorCommand.h
        command/deattach/DeattachConveyorCommand.cpp
        command/deattach/DeattachConveyorCommand.h
        command/attachCommands/AttachConveyorManagerCommand.cpp
        command/attachCommands/AttachConveyorManagerCommand.h
        command/deattach/DeattachConveyorManagerCommand.cpp
        command/deattach/DeattachConveyorManagerCommand.h
        gui/FiltersScene.cpp gui/FiltersScene.h
        gui/FiltersView.cpp gui/FiltersView.h
        gui/FiltersWindow.cpp gui/FiltersWindow.h
        IConveyorObserver.h
        IConveyorSubject.h)

target_link_libraries(filters Qt5::Core)
target_link_libraries(filters Qt5::Gui)
target_link_libraries(filters Qt5::Widgets)

