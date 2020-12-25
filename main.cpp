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
#include "Filters.h"



int main() {
    Filters filters = Filters();
    auto createConv = std::make_shared<CreateConveyorCommand>(filters.getConveyorManager());
    auto createNo = std::make_shared<CreateNodeCommand>(0, NodeType::NodeInput, filters.getConveyorManager());
    auto createNeg = std::make_shared<CreateNodeCommand>(0, NodeType::NegativeNode, filters.getConveyorManager());
    auto createNS = std::make_shared<CreateNodeCommand>(0, NodeType::GaussianNoiseNode, filters.getConveyorManager());
    auto createComb = std::make_shared<CreateNodeCommand>(0, NodeType::CombineNode, filters.getConveyorManager());
    auto createCon = std::make_shared<CreateConnectionCommand>(filters.getConveyorManager(), 0, 1, 2);
    auto createCon1 = std::make_shared<CreateConnectionCommand>(filters.getConveyorManager(), 0, 2, 4);
    auto createCon2 = std::make_shared<CreateConnectionCommand>(filters.getConveyorManager(), 0, 3, 4);
    auto createCon3 = std::make_shared<CreateConnectionCommand>(filters.getConveyorManager(), 0, 4, 0);
    auto setInp = std::make_shared<SetNodeInputCommand>(filters.getConveyorManager(), 0, 1, "anon.ppm");
    auto setOutp = std::make_shared<SetNodeOutputCommand>(filters.getConveyorManager(), 0, "anon1.ppm");
    auto setNS = std::make_shared<SetGaussianNoiseCommand>(filters.getConveyorManager(), 0, 3, 10000, 500, 500);
    auto pro = std::make_shared<ProcessCommand>(0, filters.getConveyorManager());

    filters.executeCommand(createConv);
    filters.executeCommand(createNo);
    filters.executeCommand(createNeg);
    filters.executeCommand(createNS);
    filters.executeCommand(createComb);
    filters.executeCommand(createCon);
    filters.executeCommand(createCon1);
    filters.executeCommand(createCon2);
    filters.executeCommand(createCon3);
    filters.executeCommand(setInp);
    filters.executeCommand(setOutp);
    filters.executeCommand(setNS);
    filters.executeCommand(pro);

    return 0;
}
