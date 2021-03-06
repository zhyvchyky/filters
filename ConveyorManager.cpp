//
// Created by makstsar on 27.10.2020.
//

#include <iostream>
#include <fstream>

#include "ConveyorManager.h"

size_t ConveyorManager::createConveyor() {
    if (curId == conveyors.size())
        conveyors[curId] = std::make_shared<Conveyor>();
    else
        this->conveyors[curId] = std::make_shared<Conveyor>();
    notify();
    return curId++;
}

void ConveyorManager::deleteConveyor(size_t id) {
    this->conveyors.erase(id);
    notify();
}

std::shared_ptr<Conveyor> ConveyorManager::getConveyorByID(size_t id) {
    return this->conveyors[id];
}

std::map<size_t, std::shared_ptr<Conveyor>> ConveyorManager::getConveyors() {
    return this->conveyors;
}
