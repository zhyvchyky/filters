//
// Created by makstar on 23.12.2020.
//

#include "CreateConnectionCommand.h"

CreateConnectionCommand::CreateConnectionCommand(std::shared_ptr<ConveyorManager> rec, size_t conveyorId, std::shared_ptr<ANode> inputNode, std::shared_ptr<ANode> outputNode) {
    this->receiver = rec;
    this->conveyorId = conveyorId;
    this->inputNode = inputNode;
    this->outputNode = outputNode;
}

bool CreateConnectionCommand::execute() {
    this->receiver->getConveyorByID(conveyorId)->createConnection(inputNode, outputNode);
    return true;
}
