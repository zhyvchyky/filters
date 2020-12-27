//
// Created by makstar on 23.12.2020.
//

#include "CreateConnectionCommand.h"

CreateConnectionCommand::CreateConnectionCommand(std::shared_ptr<ConveyorManager> rec, size_t conveyorId, size_t inputNodeId, size_t outputNodeId) {
    this->receiver = rec;
    this->conveyorId = conveyorId;
    this->inputNodeId = inputNodeId;
    this->outputNodeId = outputNodeId;
}

bool CreateConnectionCommand::execute() {
    this->receiver->getConveyorByID(conveyorId)->createConnection(inputNodeId, outputNodeId);
    return true;
}
