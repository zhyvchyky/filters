//
// Created by makstsar on 27.10.2020.
//

#include <iostream>

#include "ConveyorManager.h"

std::shared_ptr<Conveyor> ConveyorManager::createConveyor() {
    auto id = this->idGenerator.getNewId() - 1;

    if(this->conveyors.size() == id)
        conveyors.push_back(std::make_shared<Conveyor>());
    else
        this->conveyors[id] = std::make_shared<Conveyor>();

    return this->conveyors[id];
}

void ConveyorManager::deleteConveyor(size_t id) {
    this->conveyors[id] = nullptr;
    this->idGenerator.freeId(id);
}
