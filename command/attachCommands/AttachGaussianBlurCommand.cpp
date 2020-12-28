//
// Created by makstar on 26.12.2020.
//

#include "AttachGaussianBlurCommand.h"

AttachGaussianBlurCommand::AttachGaussianBlurCommand(std::shared_ptr<ConveyorManager> rec, size_t nI, size_t cI, std::shared_ptr<IObserver<GaussianBlurNode> > card)
        : AAttachCommand<IObserver<GaussianBlurNode> >(rec, nI, cI, card){
}

bool AttachGaussianBlurCommand::execute() {
    auto nodeGB = std::dynamic_pointer_cast<GaussianBlurNode>(this->receiver->getConveyorByID(this->conveyorId)->nodes[this->nodeId]);
    nodeGB->subscribe(this->card);
    return false;
}