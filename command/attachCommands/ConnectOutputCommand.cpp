//
// Created by makstar on 26.12.2020.
//

#include "ConnectOutputCommand.h"

ConnectOutputCommand::ConnectOutputCommand(std::shared_ptr<ConveyorManager> rec, size_t cI, size_t nI, std::shared_ptr<IObserver<NodeOutput>> card)
        :AConnectCommand<IObserver<NodeOutput>>(rec, cI, nI, card){
}

bool ConnectOutputCommand::execute() {
    auto nodeOutput = std::dynamic_pointer_cast<NodeOutput>(this->receiver->getConveyorByID(this->conveyorId)->nodes[this->nodeId]);
    nodeOutput->subscribe(this->card);
    return false;
}