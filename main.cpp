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
#include "command/DisconnectColorGeneratorCommand.h"
#include "command/ConnectConveyorCommand.h"
#include "command/ConnectConveyorManagerCommand.h"
#include "command/DisconnectConveyorCommand.h"
#include "command/DisconnectConveyorManagerCommand.h"
#include "cards/ConveyorCard.h"
#include "cards/ConveyorManagerCard.h"
int main() {
    auto filters = std::make_shared<Filters>();
    auto cardConveyorManager = std::make_shared<ConveyorManagerCard>();
    auto conn = std::make_shared<ConnectConveyorManagerCommand>(filters->getConveyorManager(), cardConveyorManager);
    filters->executeCommand(conn);
    auto cc1 = std::make_shared<CreateConveyorCommand>(filters->getConveyorManager());
    filters->executeCommand(cc1);

    auto cc2 = std::make_shared<CreateConveyorCommand>(filters->getConveyorManager());
    filters->executeCommand(cc2);

    std::cout<<cardConveyorManager->getConveyors().size();

    auto dcc = std::make_shared<DisconnectConveyorManagerCommand>(filters->getConveyorManager(), cardConveyorManager);
    filters->executeCommand(dcc);
    auto conn1 = std::make_shared<ConnectConveyorManagerCommand>(filters->getConveyorManager(), cardConveyorManager);
    filters->executeCommand(conn1);

    std::cout<<cardConveyorManager->getConveyors().size();


    auto deleteConveyorCommand = std::make_shared<DeleteConveyorCommand>(filters->getConveyorManager(), 0);
    filters->executeCommand(deleteConveyorCommand);
    std::cout<<cardConveyorManager->getConveyors().size();
//    auto filters = std::make_shared<Filters>();
////Create Conveyor
//    auto conveyor = std::make_shared<CreateConveyorCommand>(filters->getConveyorManager());
////Create Card ConveyorManager
//    auto cardConveyorManager = std::make_shared<ConveyorManagerCard>();
//    auto connectConveyorManager = std::make_shared<ConnectConveyorManagerCommand>(filters->getConveyorManager(), cardConveyorManager);
////Create Card Conveyor
//    auto cardConveyor = std::make_shared<ConveyorCard>();
//    auto connectConveyor = std::make_shared<ConnectConveyorCommand>(filters->getConveyorManager(), 0, cardConveyor);
//// Create BaW Node and Card
//    auto node2 = std::make_shared<CreateNodeCommand>(filters->getConveyorManager(),0, NodeType::BlackAndWhiteNode);
////    auto connectnode2 = std::make_shared<CreateConnectionCommand>(filters->getConveyorManager(),0,0,1);
//
//// Create Negative Node and Card
//    auto node = std::make_shared<CreateNodeCommand>(filters->getConveyorManager(),0, NodeType::NegativeNode);
//    auto connectnode = std::make_shared<CreateConnectionCommand>(filters->getConveyorManager(),0,1,2);
////test
//    auto DConv = std::make_shared<DisconnectConveyorCommand>(filters->getConveyorManager(),0, cardConveyor);
//// Create Input Node and Card and set config
//    auto nodeI = std::make_shared<CreateNodeCommand>(filters->getConveyorManager(),0, NodeType::NodeInput);
//    auto cardI = std::make_shared<NodeInputCard>();
//    auto connectI = std::make_shared<ConnectInputCommand>(filters->getConveyorManager(),0,3, cardI);
//    auto setC = std::make_shared<SetNodeInputCommand>(filters->getConveyorManager(), 0, 3, "D:\\projects\\cherniy.ppm");
//    auto conI = std::make_shared<CreateConnectionCommand>(filters->getConveyorManager(),0,3,1);
//
//
//// Create NodeOutputCard and set config
//    auto cardO = std::make_shared<NodeOutputCard>();
//    auto connectO = std::make_shared<ConnectOutputCommand>(filters->getConveyorManager(),0,0, cardO);
//    auto setCO = std::make_shared<SetNodeOutputCommand>(filters->getConveyorManager(), 0, "D:\\projects\\fuck.ppm");
//
////Connect out and negative
//    auto connectOut = std::make_shared<CreateConnectionCommand>(filters->getConveyorManager(), 0, 2, 0);
//// process
//    auto process = std::make_shared<ProcessCommand>(filters->getConveyorManager(), 0);
//
//    filters->executeCommand(conveyor);
//    filters->executeCommand(connectConveyorManager);
//    filters->executeCommand(connectConveyor);
//    filters->executeCommand(node2);
////    filters->executeCommand(connectnode2);
//    filters->executeCommand(node);
//    filters->executeCommand(connectnode);
//    filters->executeCommand(DConv);
//    filters->executeCommand(nodeI);
//    std::cout<<cardConveyor->getNodes().size();
//    filters->executeCommand(connectI);
//    filters->executeCommand(setC);
//    filters->executeCommand(conI);
//    filters->executeCommand(connectO);
//    filters->executeCommand(setCO);
//    filters->executeCommand(connectOut);
//    filters->executeCommand(process);

//    auto card = std::make_shared<ConveyorManagerCard>();
//    auto c1 = std::make_shared<ConnectConveyorManagerCommand>(filters,card);
//    auto c2 = std::make_shared<CreateConveyorCommand>(filters->getConveyorManager());
//    auto c3 = std::make_shared<DisconnectConveyorManagerCommand>(filters,card);
//    auto c4 = std::make_shared<CreateConveyorCommand>(filters->getConveyorManager());
//    filters->executeCommand(c1);
//    filters->executeCommand(c2);
//    filters->executeCommand(c3);
//    filters->executeCommand(c4);

//    auto createConv = std::make_shared<CreateConveyorCommand>(filters.getConveyorManager());
//    filters.executeCommand(createConv);
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
//    auto co0 = std::make_shared<NodeOutputCard>();
//    auto q1 = std::make_shared<ConnectInputCommand>(filters.getConveyorManager(), 0, 1, co1);
//    auto q2 = std::make_shared<ConnectColorGeneratorCommand>(filters.getConveyorManager(), 0, 2, co2);
//    auto q3 = std::make_shared<ConnectGaussianBlurCommand>(filters.getConveyorManager(), 0, 3, co3);
//    auto q4 = std::make_shared<ConnectGaussianNoiseCommand>(filters.getConveyorManager(), 0, 4, co4);
//    auto q5 = std::make_shared<ConnectMedianCommand>(filters.getConveyorManager(), 0, 5, co5);
//    auto q0 = std::make_shared<ConnectOutputCommand>(filters.getConveyorManager(),0,0, co0);
//    filters.executeCommand(q1);
//    filters.executeCommand(q2);
//    filters.executeCommand(q3);
//    filters.executeCommand(q4);
//    filters.executeCommand(q5);
//    filters.executeCommand(q0);
//    auto s0 = std::make_shared<SetNodeOutputCommand>(filters.getConveyorManager(), 0,"D:\\projects\\lastOne.ppm");
//    auto s1 = std::make_shared<SetNodeInputCommand>(filters.getConveyorManager(), 0,1,"D:\\projects\\anon.ppm");
//    auto s2 = std::make_shared<SetColorGeneratorCommand>(filters.getConveyorManager(), 0,2,0,0,0,5,5);
//    auto s3 = std::make_shared<SetGaussianBlurCommand>(filters.getConveyorManager(), 0, 3, 2);
//    auto s4 = std::make_shared<SetGaussianNoiseCommand>(filters.getConveyorManager(), 0, 4, 5, 5, 5);
//    auto s5 = std::make_shared<SetMedianCommand>(filters.getConveyorManager(), 0,5, 1);
//    filters.executeCommand(s0);
//    filters.executeCommand(s1);
//    filters.executeCommand(s2);
//    filters.executeCommand(s3);
//    filters.executeCommand(s4);
//    filters.executeCommand(s5);
//    std::cout<<co1->getFilePath()<<std::endl;
//    std::cout<<co0->getFilePath()<<std::endl;
//    int i1,i2,i3,i4,i5;
//    std::tie(i1,i2,i3,i4,i5) = co2->getColor();
//    std::cout<<i1<<i2<<i3<<i4<<i5<<std::endl;
//    auto oafj=std::make_shared<DisconnectColorGeneratorCommand>(filters.getConveyorManager(), 0, 2, co2);
//    filters.executeCommand(oafj);
//    auto stest = std::make_shared<SetColorGeneratorCommand>(filters.getConveyorManager(), 0,2,0,999990,0,5,5);
//    filters.executeCommand(stest);
//    std::tie(i1,i2,i3,i4,i5) = co2->getColor();
//    std::cout<<i1<<i2<<i3<<i4<<i5<<std::endl;
//    auto p = std::make_shared<ProcessCommand>(0, filters.getConveyorManager());
//    filters.executeCommand(p);

    return 0;
}
