//
// Created by makstar on 23.12.2020.
//

#include "DeleteConnectionCommand.h"

DeleteConnectionCommand::DeleteConnectionCommand(std::shared_ptr<ConveyorManager> rec, size_t conveyorId, std::shared_ptr<ANode> inputNode, std::shared_ptr<ANode> outputNode) {
    this->receiver = rec;
    this->conveyorId = conveyorId;
    this->inputNode = inputNode;
    this->outputNode = outputNode;
}

bool DeleteConnectionCommand::execute() {
    this->receiver->getConveyorByID(conveyorId)->deleteConnection(inputNode, outputNode);
    return true;
}