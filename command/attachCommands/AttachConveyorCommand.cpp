//
// Created by makstsar on 27.12.2020.
//

#include "AttachConveyorCommand.h"

AttachConveyorCommand::AttachConveyorCommand(std::shared_ptr<ConveyorManager> rec, size_t id, std::shared_ptr<IConveyorObserver> c) {
    this->receiver = rec;
    this->conveyorId = id;
    this->card = c;
}

bool AttachConveyorCommand::execute() {
    this->receiver->getConveyorByID(this->conveyorId)->subscribe(this->card);
    this->card->notify(this->receiver->getConveyorByID(this->conveyorId));
    return false;
}
