//
// Created by makstsar on 27.12.2020.
//

#include "DisconnectInputCommand.h"

DisconnectInputCommand::DisconnectInputCommand(std::shared_ptr<ConveyorManager> rec, size_t cI, size_t nI, std::shared_ptr<IObserver<NodeInput>> card)
        :AConnectCommand<IObserver<NodeInput>>(rec, cI, nI, card){
}

bool DisconnectInputCommand::execute() {
    auto nodeInput = std::dynamic_pointer_cast<NodeInput>(this->receiver->getConveyorByID(this->conveyorId)->nodes[this->nodeId]);
    nodeInput->unsubscribe(this->card);
    return false;
}