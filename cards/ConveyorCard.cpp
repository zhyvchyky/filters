//
// Created by makstsar on 27.12.2020.
//

#include "ConveyorCard.h"

std::map<size_t, std::shared_ptr<ANode>> ConveyorCard::getNodes() {
    return this->nodes;
}

void ConveyorCard::notify(std::shared_ptr<Conveyor> conv) {
    this->nodes = conv->getNodes();
}
