//
// Created by noxin on 12/23/20.
//

#include "CreateNodeCommand.h"

CreateNodeCommand::CreateNodeCommand(std::shared_ptr<ConveyorManager> rec, size_t conveyorId, NodeType nodeType) {
    this->conveyorId = conveyorId;
    this->nodeType = nodeType;
    this->receiver = rec;
}

bool CreateNodeCommand::execute() {
    this->receiver->getConveyorByID(this->conveyorId)->createNode(this->nodeType);
    return true;
}
