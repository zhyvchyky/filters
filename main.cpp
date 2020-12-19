// Created by noxin on 10/27/20.
//

#include <iostream>
#include "Filters.h"
#include "Conveyor.h"

#include "nodes/NodeInput.h"
#include "nodes/NodeOutput.h"
#include "nodes/EdgeDetectionNode.h"

int main() {
    auto nodeInput = std::make_shared<NodeInput>();
    auto nodeOutput = std::make_shared<NodeOutput>();
    auto nodeDet = std::make_shared<EdgeDetectionNode>();


    nodeInput->setFilePath({"/home/linups/repos/project_updated/filters/anon.ppm"});
    nodeDet->setInput(0, nodeInput);
    nodeOutput->setInput(0, nodeDet);
    nodeOutput->setFilePath({"/home/linups/repos/project_updated/filters/anon1.ppm"});
    nodeInput->process();
    nodeDet->process();
    nodeOutput->process();
    return 0;
}
