//
// Created by makstar on 26.12.2020.
//

#include "ConnectGaussianBlurCommand.h"

ConnectGaussianBlurCommand::ConnectGaussianBlurCommand(std::shared_ptr<ConveyorManager> rec, size_t nI, size_t cI, std::shared_ptr<GaussianBlurCard> card)
        :AConnectCommand<GaussianBlurCard>(rec, nI, cI, card){
}

bool ConnectGaussianBlurCommand::execute() {
    auto nodeGB = std::dynamic_pointer_cast<GaussianBlurNode>(this->receiver->getConveyorByID(this->conveyorId)->nodes[this->nodeId]);
    nodeGB->subscribe(this->card);
    return false;
}