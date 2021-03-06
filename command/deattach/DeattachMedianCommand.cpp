//
// Created by makstsar on 27.12.2020.
//

#include "DeattachMedianCommand.h"

DeattachMedianCommand::DeattachMedianCommand(std::shared_ptr<ConveyorManager> rec, size_t cI, size_t nI, std::shared_ptr<IObserver<MedianNode>> card)
        : AAttachCommand<IObserver<MedianNode>>(rec, cI, nI, card){
}

bool DeattachMedianCommand::execute() {
    auto nodeMedian = std::dynamic_pointer_cast<MedianNode>(this->receiver->getConveyorByID(this->conveyorId)->nodes[this->nodeId]);
    nodeMedian->unsubscribe(this->card);
    return false;
}