//
// Created by makstsar on 27.12.2020.
//

#include "DeattachConveyorManagerCommand.h"

DeattachConveyorManagerCommand::DeattachConveyorManagerCommand(std::shared_ptr<ConveyorManager> f, std::shared_ptr<IObserver<ConveyorManager>> c) {
    this->receiver = f;
    this->card = c;
}

bool DeattachConveyorManagerCommand::execute() {
    this->receiver->unsubscribe(this->card);
    return false;
}
