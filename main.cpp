// Created by noxin on 10/27/20.
//

#include <iostream>

#include "command/CreateConveyorCommand.h"
#include "command/CreateNodeCommand.h"
#include "command/CreateConnectionCommand.h"
#include "command/DeleteConveyorCommand.h"
#include "command/DeleteNodeCommand.h"
#include "command/DeleteConnectionCommand.h"
#include "command/ProcessCommand.h"
#include "command/SetNodeInputCommand.h"
#include "command/SetNodeOutputCommand.h"
#include "command/SetGaussianNoiseCommand.h"
#include "command/SetColorGeneratorCommand.h"
#include "command/SetGaussianBlurCommand.h"
#include "command/SetMedianCommand.h"
#include "Filters.h"
#include "cards/GaussianBlurCard.h"
#include "cards/NodeInputCard.h"
#include "cards/NodeOutputCard.h"
#include "cards/MedianCard.h"
#include "cards/GaussianNoiseCard.h"
#include "cards/ColorGeneratorCard.h"
#include "command/ConnectGaussianBlurCommand.h"
#include "command/ConnectInputCommand.h"
#include "command/ConnectColorGeneratorCommand.h"
#include "command/ConnectGaussianNoiseCommand.h"
#include "command/ConnectMedianCommand.h"
#include "command/ConnectOutputCommand.h"

int main() {
    Filters filters = Filters();
    auto createConv = std::make_shared<CreateConveyorCommand>(filters.getConveyorManager());
    auto n = std::make_shared<CreateNodeCommand>(0, NodeType::NegativeNode, filters.getConveyorManager());
    filters.executeCommand(n);
//    auto n1 = std::make_shared<CreateNodeCommand>(0, NodeType::NodeInput, filters.getConveyorManager());
//    auto n2 = std::make_shared<CreateNodeCommand>(0, NodeType::ColorGeneratorNode, filters.getConveyorManager());
//    auto n3 = std::make_shared<CreateNodeCommand>(0, NodeType::GaussianBlurNode, filters.getConveyorManager());
//    auto n4 = std::make_shared<CreateNodeCommand>(0, NodeType::GaussianNoiseNode, filters.getConveyorManager());
//    auto n5 = std::make_shared<CreateNodeCommand>(0, NodeType::MedianNode, filters.getConveyorManager());
//    auto c1 = std::make_shared<CreateConnectionCommand>(filters.getConveyorManager(), 0, 1, 2);
//    auto c2 = std::make_shared<CreateConnectionCommand>(filters.getConveyorManager(), 0, 2, 3);
//    auto c3 = std::make_shared<CreateConnectionCommand>(filters.getConveyorManager(), 0, 3, 4);
//    auto c4 = std::make_shared<CreateConnectionCommand>(filters.getConveyorManager(), 0, 4, 5);
//    auto c5 = std::make_shared<CreateConnectionCommand>(filters.getConveyorManager(), 0, 5, 0);
//    filters.executeCommand(n1);
//    filters.executeCommand(n2);
//    filters.executeCommand(n3);
//    filters.executeCommand(n4);
//    filters.executeCommand(n5);
//    filters.executeCommand(c1);
//    filters.executeCommand(c2);
//    filters.executeCommand(c3);
//    filters.executeCommand(c4);
//    filters.executeCommand(c5);
//    auto co1 = std::make_shared<NodeInputCard>();
//    auto co2 = std::make_shared<ColorGeneratorCard>();
//    auto co3 = std::make_shared<GaussianBlurCard>();
//    auto co4 = std::make_shared<GaussianNoiseCard>();
//    auto co5 = std::make_shared<MedianCard>();
//    auto q1 = std::make_shared<ConnectInputCommand>(filters.getConveyorManager(), 0, 1, co1);
//    auto q2 = std::make_shared<ConnectColorGeneratorCommand>(filters.getConveyorManager(), 0, 2, co2);
//    auto q3 = std::make_shared<ConnectGaussianBlurCommand>(filters.getConveyorManager(), 0, 3, co3);
//    auto q4 = std::make_shared<ConnectGaussianNoiseCommand>(filters.getConveyorManager(), 0, 4, co4);
//    auto q5 = std::make_shared<ConnectMedianCommand>(filters.getConveyorManager(), 0, 5, co5);
//    filters.executeCommand(q1);
//    filters.executeCommand(q2);
//    filters.executeCommand(q3);
//    filters.executeCommand(q4);
//    filters.executeCommand(q5);
//    auto s0 = std::make_shared<SetNodeOutputCommand>(filters.getConveyorManager(), 0,"D:\\projects\\lastOne.ppm");
//    auto s1 = std::make_shared<SetNodeInputCommand>(filters.getConveyorManager(), 0,1,"D:\\projects\\anon.ppm");
//    auto s2 = std::make_shared<SetColorGeneratorCommand>(filters.getConveyorManager(), 0,2,0,0,0,5,5);
//    auto s3 = std::make_shared<SetGaussianBlurCommand>(filters.getConveyorManager(), 0, 3, 2);
//    auto s4 = std::make_shared<SetGaussianNoiseCommand>(filters.getConveyorManager(), 0, 4, 5, 5, 5);
//    auto s5 = std::make_shared<SetMedianCommand>(filters.getConveyorManager(), 0,5, 1);
//    filters.executeCommand(s1);
//    filters.executeCommand(s2);
//    filters.executeCommand(s3);
//    filters.executeCommand(s4);
//    filters.executeCommand(s5);
//    std::cout<<co1->getFilePath()<<std::endl;
//    auto p = std::make_shared<ProcessCommand>(0, filters.getConveyorManager());
//    filters.executeCommand(p);

    return 0;
}
