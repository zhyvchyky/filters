//
// Created by linups on 12/25/20.
//

#include "SetGaussianBlurCommand.h"

SetGaussianBlurCommand::SetGaussianBlurCommand(std::shared_ptr<ConveyorManager> rec, size_t conveyorId, size_t nodeId, int blurRadius) {
    this->receiver = rec;
    this->conveyorId = conveyorId;
    this->nodeId = nodeId;
    this->blurRadius = blurRadius;
}

bool SetGaussianBlurCommand::execute() {
    auto blurNode = std::dynamic_pointer_cast<GaussianBlurNode>(this->receiver->getConveyorByID(conveyorId)->nodes[nodeId]);
    if(blurNode != nullptr){
        blurNode->setRadius(blurRadius);
        return true;
    }
    return false;
}

