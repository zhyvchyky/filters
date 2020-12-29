//
// Created by makstsar on 27.12.2020.
//

#include "ConveyorCard.h"

std::set<size_t> ConveyorCard::getNodes() {
    return this->nodes;
}

void ConveyorCard::notify(std::shared_ptr<Conveyor> conv) {
    this->nodes.erase(this->nodes.begin(),this->nodes.end());

    auto nodesVector = conv->getNodes();
    for(size_t i = 0; i < nodesVector.size(); i++){
        if(nodesVector[i] != nullptr){
            nodes.insert(i);
        }
    }

    for(int i = 0; i < nodesVector.size(); i++){
        for(const auto& node: nodesVector[i]->getOutputs()){
            for(int j = 0; j < nodesVector.size(); i++){
                if(node == nodesVector[j])
                    this->connections[i] = j;
            }
        }
    }
}
