//
// Created by makstsar on 27.12.2020.
//

#include "ConnectConveyorManagerCommand.h"

ConnectConveyorManagerCommand::ConnectConveyorManagerCommand(std::shared_ptr<ConveyorManager> f, std::shared_ptr<IObserver<ConveyorManager>> c) {
this->receiver = f;
this->card = c;
}

bool ConnectConveyorManagerCommand::execute() {
    this->receiver->subscribe(this->card);
    return false;
}
