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
#include "Filters.h"



int main() {
    Filters filters;
    auto createConveyorCommand = std::make_shared<CreateConveyorCommand>(filters.getConveyorManager());
    createConveyorCommand->execute();
    auto createNodeCommand1 = std::make_shared<CreateNodeCommand>(0, NodeType::BlackAndWhiteNode, filters.getConveyorManager());
    createNodeCommand1->execute();
    auto createNodeCommand2 = std::make_shared<CreateNodeCommand>(0, NodeType::NodeInput, filters.getConveyorManager());
    createNodeCommand2->execute();
    auto pro = std::make_shared<ProcessCommand>(0, filters.getConveyorManager());
//    pro->execute();
    auto deleNodeCommand2 = std::make_shared<DeleteNodeCommand>(0, 2, filters.getConveyorManager());
    deleNodeCommand2->execute();
    auto deleNodeCommand1 = std::make_shared<DeleteNodeCommand>(0, 1, filters.getConveyorManager());
    deleNodeCommand1->execute();
    auto deleteConveyorCommand = std::make_shared<DeleteConveyorCommand>(filters.getConveyorManager(), 0);
    deleteConveyorCommand->execute();
    //filters.getConveyorManager()->com = createConveyorCommand;
//    filters.executeCommand(createConveyorCommand);

    return 0;
}
