//
// Created by makstsar on 27.12.2020.
//

#include "ConveyorCard.h"

std::map<size_t, std::shared_ptr<ANode>> ConveyorCard::getNodes() {
    return this->nodes;
}

void ConveyorCard::notify(std::shared_ptr<Conveyor> conv) {
    this->nodes = conv->getNodes();
    auto it = this->nodes.begin();
    for(auto it = this->nodes.begin(); it != this->nodes.end(); it++) {
        for (auto &node : it->second->getOutputs()) {
            for (auto it2 = this->nodes.begin(); it2 != this->nodes.end(); it2++) {
                if (node == it2->second)
                    this->connections[it->first] = it2->first;
            }
        }
    }
}
