//
// Created by makstar on 23.12.2020.
//

#include "ProcessCommand.h"

ProcessCommand::ProcessCommand(size_t conveyorId, std::shared_ptr<ConveyorManager> rec) {
    this->conveyorId = conveyorId;
    this->receiver = rec;
}

bool ProcessCommand::execute() {
    this->receiver->getConveyorByID(this->conveyorId)->process();
    return false;
}