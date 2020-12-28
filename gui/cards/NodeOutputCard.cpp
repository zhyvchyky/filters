//
// Created by makstsar on 26.12.2020.
//

#include "NodeOutputCard.h"

std::string NodeOutputCard::getFilePath() {
    return this->filepath;
}

void NodeOutputCard::notify(std::shared_ptr<NodeOutput> node) {
    this->filepath = node->getFilePath();
}
