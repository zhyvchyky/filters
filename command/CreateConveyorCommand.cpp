//
// Created by noxin on 12/23/20.
//

#include "CreateConveyorCommand.h"

CreateConveyorCommand::CreateConveyorCommand(std::shared_ptr<ConveyorManager> rec) {
    this->receiver = rec;
}

bool CreateConveyorCommand::execute() {
    this->receiver->createConveyor();

}