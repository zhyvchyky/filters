//
// Created by makstar on 26.12.2020.
//

#include "AttachMedianCommand.h"

AttachMedianCommand::AttachMedianCommand(std::shared_ptr<ConveyorManager> rec, size_t cI, size_t nI, std::shared_ptr<IObserver<MedianNode>> card)
        : AAttachCommand<IObserver<MedianNode>>(rec, cI, nI, card){
}

bool AttachMedianCommand::execute() {
    auto nodeMedian = std::dynamic_pointer_cast<MedianNode>(this->receiver->getConveyorByID(this->conveyorId)->nodes[this->nodeId]);
    nodeMedian->subscribe(this->card);
    return false;
}