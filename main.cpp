// Created by noxin on 10/27/20.
//

#include <iostream>


#include "nodes/NegativeNode.h"
#include "cards/NodeInputCard.h"


#include "Conveyor.h"

int main() {
    Conveyor conveyor;
    std::shared_ptr<ANode> nodeIn = conveyor.createNode(NodeType::NodeInput);

    auto nodeInd = std::dynamic_pointer_cast<NodeInput>(nodeIn);

    auto card = std::make_shared<NodeInputCard>();
    nodeInd->subscribe(card);
    nodeInd->setFilePath("/home/linups");
    std::cout << card->getFilePath() << std::endl;
    nodeInd->unsubscribe(card);
    nodeInd->setFilePath("/home/Noxin");
    std::cout << card->getFilePath() << std::endl;
    return 0;
}
