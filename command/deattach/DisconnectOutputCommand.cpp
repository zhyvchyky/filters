//
// Created by makstsar on 27.12.2020.
//

#include "DisconnectOutputCommand.h"

DisconnectOutputCommand::DisconnectOutputCommand(std::shared_ptr<ConveyorManager> rec, size_t cI, size_t nI, std::shared_ptr<IObserver<NodeOutput>> card)
        :AConnectCommand<IObserver<NodeOutput>>(rec, cI, nI, card){
}

bool DisconnectOutputCommand::execute() {
    auto nodeOutput = std::dynamic_pointer_cast<NodeOutput>(this->receiver->getConveyorByID(this->conveyorId)->nodes[this->nodeId]);
    nodeOutput->unsubscribe(this->card);
    return false;
}