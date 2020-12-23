// Created by noxin on 10/27/20.
//

#include <iostream>


#include "nodes/NegativeNode.h"
#include "cards/NodeInputCard.h"
#include "cards/GaussianBlurCard.h"


#include "Conveyor.h"

#include "Conveyor.h"

int main() {
    Conveyor conveyor;

    std::shared_ptr<ANode> nodeIn = conveyor.createNode(NodeType::GaussianBlurNode);

    auto nodeInd = std::dynamic_pointer_cast<GaussianBlurNode>(nodeIn);

    auto card = std::make_shared<GaussianBlurCard>();
    nodeInd->subscribe(card);
    nodeInd->setRadius(10);
    std::cout << card->getRadius() << std::endl;
    nodeInd->unsubscribe(card);
    nodeInd->setRadius(15);
    std::cout << card->getRadius() << std::endl;

    return 0;
}
