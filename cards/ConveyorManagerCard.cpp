//
// Created by makstsar on 27.12.2020.
//

#include "ConveyorManagerCard.h"

std::vector<std::shared_ptr<Conveyor>> ConveyorManagerCard::getConveyors() {
    return this->conveyors;
}

void ConveyorManagerCard::notify(std::shared_ptr<ConveyorManager> man) {
    this->conveyors = man->getConveyors();
}
