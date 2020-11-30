// Created by noxin on 10/27/20.
//

#include <iostream>
#include "Filters.h"
#include "Conveyor.h"

#include "nodes/NodeInput.h"

int main() {
    NodeInput nodeInput = NodeInput();

    nodeInput.setFields({});
    nodeInput.process();

    return 0;
}
