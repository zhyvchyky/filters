//
// Created by linups on 12/25/20.
//

#include "SetColorGeneratorCommand.h"

SetColorGeneratorCommand::SetColorGeneratorCommand(std::shared_ptr<ConveyorManager> rec, size_t conveyorId, size_t nodeId, int red, int green, int blue, int width, int height) {
    this->receiver = rec;
    this->conveyorId = conveyorId;
    this->nodeId = nodeId;
    this->red = red;
    this->green = green;
    this->blue = blue;
    this->width = width;
    this->height = height;
}

bool SetColorGeneratorCommand::execute() {
    auto colorNode = std::dynamic_pointer_cast<ColorGeneratorNode>(this->receiver->getConveyorByID(conveyorId)->nodes[nodeId]);
    if(colorNode != nullptr){
        colorNode->setColorValues(red, green, blue, height, width);
        return true;
    }
    return false;
}
