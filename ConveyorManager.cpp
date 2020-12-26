//
// Created by makstsar on 27.10.2020.
//

#include <iostream>
#include <fstream>

#include "ConveyorManager.h"

size_t ConveyorManager::createConveyor() {
    auto id = this->idGenerator.getNewId() - 1;
    this->conveyors[id] = std::make_shared<Conveyor>();
    return id;
}

void ConveyorManager::deleteConveyor(size_t id) {
    this->conveyors[id] = nullptr;
    this->idGenerator.freeId(id);
}

std::shared_ptr<Conveyor> ConveyorManager::getConveyorByID(size_t id) {
    return this->conveyors[id];
}

std::map<size_t, std::shared_ptr<Conveyor>> ConveyorManager::getConveyors() {
    return this->conveyors;
}
