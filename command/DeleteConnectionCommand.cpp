//
// Created by makstar on 23.12.2020.
//

#include "DeleteConnectionCommand.h"

DeleteConnectionCommand::DeleteConnectionCommand(std::shared_ptr<ConveyorManager> rec, size_t conveyorId, size_t inputNodeId, size_t outputNodeId) {
    this->receiver = rec;
    this->conveyorId = conveyorId;
    this->inputNodeId = inputNodeId;
    this->outputNodeId = outputNodeId;
}

bool DeleteConnectionCommand::execute() {
    this->receiver->getConveyorByID(conveyorId)->deleteConnection(inputNodeId, outputNodeId);
    return true;
}