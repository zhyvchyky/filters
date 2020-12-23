//
// Created by makstar on 23.12.2020.
//

#include "DeleteConveyorCommand.h"

DeleteConveyorCommand::DeleteConveyorCommand(std::shared_ptr<ConveyorManager> rec, size_t conveyorId) {
    this->receiver = rec;
    this->conveyorId = conveyorId;
}

bool DeleteConveyorCommand::execute() {
    this->receiver->deleteConveyor(conveyorId);
    return true;
}