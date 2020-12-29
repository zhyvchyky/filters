//
// Created by makstsar on 27.12.2020.
//

#include "ConveyorManagerCard.h"

std::set<size_t> ConveyorManagerCard::getConveyors() {
    return this->conveyors;
}

void ConveyorManagerCard::notify(std::shared_ptr<ConveyorManager> man) {
    this->conveyors.erase(this->conveyors.begin(),this->conveyors.end());
    auto conveyorsVector = man->getConveyors();
    for(size_t i = 0; i < conveyorsVector.size(); i++){
        if(conveyorsVector[i] != nullptr){
            conveyors.insert(i);
        }
    }
}
