//
// Created by noxin on 12/23/20.
//

#include "NodeInputCard.h"

void NodeInputCard::notify(std::shared_ptr<NodeInput> node) {
    this->filepath = node->getFilePath();
}

std::string NodeInputCard::getFilePath() {
    return this->filepath;
}
