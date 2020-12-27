//
// Created by makstsar on 27.12.2020.
//

#include "DisconnectConveyorManagerCommand.h"

DisconnectConveyorManagerCommand::DisconnectConveyorManagerCommand(std::shared_ptr<ConveyorManager> f, std::shared_ptr<ConveyorManagerCard> c) {
    this->receiver = f;
    this->card = c;
}

bool DisconnectConveyorManagerCommand::execute() {
    this->receiver->unsubscribe(this->card);
    return false;
}
