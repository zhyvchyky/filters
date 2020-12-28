//
// Created by makstsar on 27.12.2020.
//

#include "AttachConveyorManagerCommand.h"

AttachConveyorManagerCommand::AttachConveyorManagerCommand(std::shared_ptr<ConveyorManager> f, std::shared_ptr<IObserver<ConveyorManager>> c) {
this->receiver = f;
this->card = c;
}

bool AttachConveyorManagerCommand::execute() {
    this->receiver->subscribe(this->card);
    return false;
}
