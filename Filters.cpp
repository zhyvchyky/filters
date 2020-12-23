//
// Created by linups on 10/27/20.
//

#include <iostream>
#include "Filters.h"
Filters::Filters(): commandHistory(500){
    this->conveyorManager = std::make_shared<ConveyorManager>();
}

std::shared_ptr<ConveyorManager> Filters::getConveyorManager() {
    return this->conveyorManager;
}

void Filters::executeCommand(std::shared_ptr<ICommand> command) {
    if(command->execute())
        commandHistory.push(command);
}
