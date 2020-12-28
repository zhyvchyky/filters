//
// Created by makstsar on 27.12.2020.
//

#include "DeattachInputCommand.h"

DeattachInputCommand::DeattachInputCommand(std::shared_ptr<ConveyorManager> rec, size_t cI, size_t nI, std::shared_ptr<IObserver<NodeInput>> card)
        : AAttachCommand<IObserver<NodeInput>>(rec, cI, nI, card){
}

bool DeattachInputCommand::execute() {
    auto nodeInput = std::dynamic_pointer_cast<NodeInput>(this->receiver->getConveyorByID(this->conveyorId)->nodes[this->nodeId]);
    nodeInput->unsubscribe(this->card);
    return false;
}