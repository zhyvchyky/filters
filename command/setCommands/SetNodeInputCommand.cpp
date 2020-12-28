//
// Created by linups on 12/25/20.
//

#include "SetNodeInputCommand.h"

SetNodeInputCommand::SetNodeInputCommand(std::shared_ptr<ConveyorManager> rec, size_t conveyorId, size_t nodeId, std::string filepath) {
    this->receiver = rec;
    this->conveyorId = conveyorId;
    this->nodeId = nodeId;
    this->filepath = filepath;
}

bool SetNodeInputCommand::execute() {
    auto inputNode = std::dynamic_pointer_cast<NodeInput>(this->receiver->getConveyorByID(conveyorId)->nodes[nodeId]);
    if(inputNode != nullptr){
        inputNode->setFilePath(filepath);
        return true;
    }
    return false;
}


