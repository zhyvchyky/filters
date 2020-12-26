//
// Created by makstar on 26.12.2020.
//

#include "ConnectMedianCommand.h"

ConnectMedianCommand::ConnectMedianCommand(std::shared_ptr<ConveyorManager> rec, size_t cI, size_t nI, std::shared_ptr<MedianCard> card)
        :AConnectCommand<MedianCard>(rec, cI, nI, card){
}

bool ConnectMedianCommand::execute() {
    auto nodeMedian = std::dynamic_pointer_cast<MedianNode>(this->receiver->getConveyorByID(this->conveyorId)->nodes[this->nodeId]);
    nodeMedian->subscribe(this->card);
    return false;
}