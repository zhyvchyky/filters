//
// Created by makstar on 26.12.2020.
//

#include "AttachGaussianNoiseCommand.h"

AttachGaussianNoiseCommand::AttachGaussianNoiseCommand(std::shared_ptr<ConveyorManager> rec, size_t cI, size_t nI, std::shared_ptr<IObserver<GaussianNoiseNode>> card)
        : AAttachCommand<IObserver<GaussianNoiseNode>>(rec, cI, nI, card){
}

bool AttachGaussianNoiseCommand::execute() {
    auto nodeGN = std::dynamic_pointer_cast<GaussianNoiseNode>(this->receiver->getConveyorByID(this->conveyorId)->nodes[this->nodeId]);
    nodeGN->subscribe(this->card);
    this->card->notify(nodeGN);
    return false;
}