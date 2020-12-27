//
// Created by linups on 12/25/20.
//

#include "SetNodeOutputCommand.h"

SetNodeOutputCommand::SetNodeOutputCommand(std::shared_ptr<ConveyorManager> rec, size_t conveyorId, std::string filepath) {
    this->receiver = rec;
    this->conveyorId = conveyorId;
    this->filepath = filepath;
}

bool SetNodeOutputCommand::execute() {
    auto outputNode = std::dynamic_pointer_cast<NodeOutput>(this->receiver->getConveyorByID(conveyorId)->nodes[0]);
    outputNode->setFilePath(filepath);
    return true;
}


