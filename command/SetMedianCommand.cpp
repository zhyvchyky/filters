//
// Created by linups on 12/25/20.
//

#include "SetMedianCommand.h"

SetMedianCommand::SetMedianCommand(std::shared_ptr<ConveyorManager> rec, size_t conveyorId, size_t nodeId, int median) {
    this->receiver = rec;
    this->conveyorId = conveyorId;
    this->nodeId = nodeId;
    this->median = median;
}

bool SetMedianCommand::execute() {
    auto medianNode = std::dynamic_pointer_cast<MedianNode>(this->receiver->getConveyorByID(conveyorId)->nodes[nodeId]);
    if(medianNode != nullptr){
        medianNode->setMedian(median);
        return true;
    }
    return false;
}


