//
// Created by makstsar on 26.12.2020.
//

#include "DeattachColorGeneratorCommand.h"

DeattachColorGeneratorCommand::DeattachColorGeneratorCommand(std::shared_ptr<ConveyorManager> rec, size_t cI, size_t nI, std::shared_ptr<IObserver<ColorGeneratorNode>> card)
        : AAttachCommand<IObserver<ColorGeneratorNode>>(rec, cI, nI, card){
}

bool DeattachColorGeneratorCommand::execute() {
    auto nodeCG = std::dynamic_pointer_cast<ColorGeneratorNode>(this->receiver->getConveyorByID(this->conveyorId)->nodes[this->nodeId]);
    nodeCG->unsubscribe(this->card);
    return false;
}