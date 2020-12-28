//
// Created by makstsar on 27.12.2020.
//

#include "DeattachGaussianNoiseCommand.h"

DeattachGaussianNoiseCommand::DeattachGaussianNoiseCommand(std::shared_ptr<ConveyorManager> rec, size_t cI, size_t nI, std::shared_ptr<IObserver<GaussianNoiseNode>> card)
        : AAttachCommand<IObserver<GaussianNoiseNode>>(rec, cI, nI, card){
}

bool DeattachGaussianNoiseCommand::execute() {
    auto nodeGN = std::dynamic_pointer_cast<GaussianNoiseNode>(this->receiver->getConveyorByID(this->conveyorId)->nodes[this->nodeId]);
    nodeGN->unsubscribe(this->card);
    return false;
}