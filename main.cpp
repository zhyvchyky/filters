// Created by noxin on 10/27/20.
//

#include <iostream>
#include "Filters.h"
//#include "Conveyor.h"

#include "nodes/NodeInput.h"
#include "nodes/NodeOutput.h"
#include "nodes/EdgeDetectionNode.h"
#include "nodes/BlackAndWhiteNode.h"
#include "nodes/GaussianBlurNode.h"
#include "nodes/NegativeNode.h"
#include "nodes/MedianNode.h"
#include "nodes/ColorGeneratorNode.h"
#include "nodes/CombineNode.h"
#include "nodes/GaussianNoiseNode.h"
#include "nodes/ColorGeneratorNode.h"

#include "Conveyor.h"

int main() {
    Conveyor conveyor;
    std::shared_ptr<ANode> nodeIn = conveyor.createNode(NodeType::NodeInput);
    std::shared_ptr<ANode> nodeBlackWhite = conveyor.createNode(NodeType::BlackAndWhiteNode);

    conveyor.createConnection(nodeIn, nodeBlackWhite);
    conveyor.createConnection(nodeBlackWhite, conveyor.getOutputNode());

    std::dynamic_pointer_cast<NodeInput>(nodeIn)->setFilePath("cherniy.ppm");

    std::dynamic_pointer_cast<NodeOutput>(conveyor.getOutputNode())->setFilePath("whitedCherniy.ppm");

    conveyor.process();

    return 0;
}
