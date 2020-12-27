//
// Created by makstsar on 27.12.2020.
//

#include "ConnectConveyorCommand.h"

ConnectConveyorCommand::ConnectConveyorCommand(std::shared_ptr<ConveyorManager> rec, size_t id, std::shared_ptr<ConveyorCard> c) {
    this->receiver = rec;
    this->conveyorId = id;
    this->card = c;
}

bool ConnectConveyorCommand::execute() {
    this->receiver->getConveyorByID(this->conveyorId)->subscribe(this->card);
    return false;
}
