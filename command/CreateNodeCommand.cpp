//
// Created by noxin on 12/23/20.
//

#include "CreateNodeCommand.h"

CreateNodeCommand::CreateNodeCommand(size_t conveyorId, NodeType nodeType, std::shared_ptr<ConveyorManager> rec) {
    this->conveyorId = conveyorId;
    this->nodeType = nodeType;
    this->receiver = rec;
}

bool CreateNodeCommand::execute() {
    this->receiver->getConveyorByID(this->conveyorId)->createNode(this->nodeType);
    return true;
}
