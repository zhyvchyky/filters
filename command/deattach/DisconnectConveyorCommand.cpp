//
// Created by makstsar on 27.12.2020.
//

#include "DisconnectConveyorCommand.h"

DisconnectConveyorCommand::DisconnectConveyorCommand(std::shared_ptr<ConveyorManager> rec, size_t id, std::shared_ptr<IObserver<Conveyor>> c) {
    this->receiver = rec;
    this->conveyorId = id;
    this->card = c;
}

bool DisconnectConveyorCommand::execute() {
    this->receiver->getConveyorByID(this->conveyorId)->unsubscribe(this->card);
    return false;
}