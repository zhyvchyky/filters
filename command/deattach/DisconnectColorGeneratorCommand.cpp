//
// Created by makstsar on 26.12.2020.
//

#include "DisconnectColorGeneratorCommand.h"

DisconnectColorGeneratorCommand::DisconnectColorGeneratorCommand(std::shared_ptr<ConveyorManager> rec, size_t cI, size_t nI, std::shared_ptr<IObserver<ColorGeneratorNode>> card)
        :AConnectCommand<IObserver<ColorGeneratorNode>>(rec, cI, nI, card){
}

bool DisconnectColorGeneratorCommand::execute() {
    auto nodeCG = std::dynamic_pointer_cast<ColorGeneratorNode>(this->receiver->getConveyorByID(this->conveyorId)->nodes[this->nodeId]);
    nodeCG->unsubscribe(this->card);
    return false;
}