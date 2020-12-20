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

int main() {
    auto nodeInput = std::make_shared<NodeInput>();
    auto nodeInput1 = std::make_shared<NodeInput>();
    auto nodeOutput = std::make_shared<NodeOutput>();
    auto nodeDet = std::make_shared<CombineNode>();
    auto nodeBW = std::make_shared<BlackAndWhiteNode>();

    nodeInput->setFilePath({"/home/linups/repos/proj/filters/cherniy.ppm"});
    nodeInput1->setFilePath({"/home/linups/repos/proj/filters/anon.ppm"});

    nodeDet->setInput(0, nodeInput);
    nodeDet->setInput(1, nodeInput1);
    nodeBW->setInput(0, nodeDet);
    nodeOutput->setInput(0, nodeBW);
    nodeOutput->setFilePath({"/home/linups/repos/proj/filters/anon1.ppm"});

    nodeInput->process();
    nodeInput1->process();
    nodeDet->process();
    nodeBW->process();
    nodeOutput->process();
    return 0;
}
