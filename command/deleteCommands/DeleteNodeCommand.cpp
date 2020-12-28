//
// Created by makstar on 23.12.2020.
//

#include "DeleteNodeCommand.h"

DeleteNodeCommand::DeleteNodeCommand(size_t conveyorId, size_t nodeId, std::shared_ptr<ConveyorManager> rec) {
    this->conveyorId = conveyorId;
    this->nodeId = nodeId;
    this->receiver = rec;
}

bool DeleteNodeCommand::execute() {
    this->receiver->getConveyorByID(this->conveyorId)->deleteNode(nodeId);
    return true;
}