//
// Created by makstsar on 27.10.2020.
//

#ifndef FILTERS_CONVEYOR_H
#define FILTERS_CONVEYOR_H

#include <map>
#include <memory>
#include <vector>

#include "Node.h"
#include "Image.h"
#include "NodeType.h"

class Conveyor {
private:
    std::map<int, std::shared_ptr<Node>> nodes;
    std::shared_ptr<Image> result;
    bool previewOn;
    int getNewId();
    bool isCyclic();

public:
    Conveyor();
    ~Conveyor();

    void createNode(NodeType nodeType);
    void deleteNode(int nodeId);
    std::vector<int> getNodeIds();
    void process();
    void createConnection(int inputNodeId, int outputNodeId, int inputIndex);
    void deleteConnection(int inputNodeId, int outputNodeId, int inputIndex);
};

#endif
