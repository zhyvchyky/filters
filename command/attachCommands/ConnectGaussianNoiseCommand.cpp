//
// Created by makstar on 26.12.2020.
//

#include "ConnectGaussianNoiseCommand.h"

ConnectGaussianNoiseCommand::ConnectGaussianNoiseCommand(std::shared_ptr<ConveyorManager> rec, size_t cI, size_t nI, std::shared_ptr<IObserver<GaussianNoiseNode>> card)
        :AConnectCommand<IObserver<GaussianNoiseNode>>(rec, cI, nI, card){
}

bool ConnectGaussianNoiseCommand::execute() {
    auto nodeGN = std::dynamic_pointer_cast<GaussianNoiseNode>(this->receiver->getConveyorByID(this->conveyorId)->nodes[this->nodeId]);
    nodeGN->subscribe(this->card);
    return false;
}