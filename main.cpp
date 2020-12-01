// Created by noxin on 10/27/20.
//

#include <iostream>
#include "Filters.h"
#include "Conveyor.h"

#include "nodes/NodeInput.h"
#include "nodes/NodeOutput.h"

int main() {
    auto nodeInput = std::make_shared<NodeInput>();
    auto nodeOutput = std::make_shared<NodeOutput>();

    nodeInput->setFields({"image.ppm"});
    nodeOutput->setInput(0, nodeInput);
    nodeOutput->setFields({"copy228.ppm"});
    nodeInput->process();
    nodeOutput->process();



    return 0;
}
