//
// Created by makstsar on 27.12.2020.
//

#include "DeattachGaussianBlurCommand.h"

DeattachGaussianBlurCommand::DeattachGaussianBlurCommand(std::shared_ptr<ConveyorManager> rec, size_t nI, size_t cI, std::shared_ptr<IObserver<GaussianBlurNode> > card)
        : AAttachCommand<IObserver<GaussianBlurNode>>(rec, nI, cI, card){
}

bool DeattachGaussianBlurCommand::execute() {
    auto nodeGB = std::dynamic_pointer_cast<GaussianBlurNode>(this->receiver->getConveyorByID(this->conveyorId)->nodes[this->nodeId]);
    nodeGB->unsubscribe(this->card);
    return false;
}