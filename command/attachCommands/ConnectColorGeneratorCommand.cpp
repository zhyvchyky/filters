//
// Created by makstsar on 26.12.2020.
//

#include "ConnectColorGeneratorCommand.h"

ConnectColorGeneratorCommand::ConnectColorGeneratorCommand(std::shared_ptr<ConveyorManager> rec, size_t cI, size_t nI, std::shared_ptr<IObserver<ColorGeneratorNode>> card)
        :AConnectCommand<IObserver<ColorGeneratorNode>>(rec, cI, nI, card){
}

bool ConnectColorGeneratorCommand::execute() {
    auto nodeCG = std::dynamic_pointer_cast<ColorGeneratorNode>(this->receiver->getConveyorByID(this->conveyorId)->nodes[this->nodeId]);
    nodeCG->subscribe(this->card);
    return false;
}