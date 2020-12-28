//
// Created by makstsar on 27.12.2020.
//

#include "DisconnectGaussianBlurCommand.h"

DisconnectGaussianBlurCommand::DisconnectGaussianBlurCommand(std::shared_ptr<ConveyorManager> rec, size_t nI, size_t cI, std::shared_ptr<IObserver<GaussianBlurNode> > card)
        :AConnectCommand<IObserver<GaussianBlurNode>>(rec, nI, cI, card){
}

bool DisconnectGaussianBlurCommand::execute() {
    auto nodeGB = std::dynamic_pointer_cast<GaussianBlurNode>(this->receiver->getConveyorByID(this->conveyorId)->nodes[this->nodeId]);
    nodeGB->unsubscribe(this->card);
    return false;
}