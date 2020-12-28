//
// Created by makstar on 26.12.2020.
//

#include "ConnectInputCommand.h"

ConnectInputCommand::ConnectInputCommand(std::shared_ptr<ConveyorManager> rec, size_t cI, size_t nI, std::shared_ptr<IObserver<NodeInput>> card)
        :AConnectCommand<IObserver<NodeInput>>(rec, cI, nI, card){
}

bool ConnectInputCommand::execute() {
    auto nodeInput = std::dynamic_pointer_cast<NodeInput>(this->receiver->getConveyorByID(this->conveyorId)->nodes[this->nodeId]);
    nodeInput->subscribe(this->card);
    return false;
}