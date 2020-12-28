//
// Created by linups on 12/25/20.
//

#include "SetGaussianNoiseCommand.h"

SetGaussianNoiseCommand::SetGaussianNoiseCommand(std::shared_ptr<ConveyorManager> rec, size_t conveyorId, size_t nodeId, int noise, int height, int width) {
    this->receiver = rec;
    this->conveyorId = conveyorId;
    this->nodeId = nodeId;
    this->noise = noise;
    this->height = height;
    this->width = width;
}

bool SetGaussianNoiseCommand::execute() {
    auto noiseNode = std::dynamic_pointer_cast<GaussianNoiseNode>(this->receiver->getConveyorByID(conveyorId)->nodes[nodeId]);
    if(noiseNode != nullptr){
        noiseNode->setNoise(noise, height, width);
        return true;
    }
    return false;
}


