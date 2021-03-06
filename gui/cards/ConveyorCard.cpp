//
// Created by makstsar on 27.12.2020.
//

#include "ConveyorCard.h"

std::set<size_t> ConveyorCard::getNodes() {
    return this->nodes;
}

void ConveyorCard::notify(std::shared_ptr<Conveyor> conv) {
    this->nodes.erase(this->nodes.begin(),this->nodes.end());

    auto nodesMap = conv->getNodes();
    for(size_t i = 0; i < nodesMap.size(); i++){
        if(nodesMap[i] != nullptr){
            nodes.insert(i);
        }
    }

    for(int i = 0; i < nodesMap.size(); i++){
        for(const auto& node: nodesMap[i]->getOutputs()){
            for(int j = 0; j < nodesMap.size(); i++){
                if(node == nodesMap[j])
                    this->connections[i] = j;
            }
        }
    }
}
