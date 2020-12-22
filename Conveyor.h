//
// Created by makstsar on 27.10.2020.
//

#ifndef FILTERS_CONVEYOR_H
#define FILTERS_CONVEYOR_H

#include <map>
#include <memory>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include "Image.h"
#include "NodeType.h"
#include "nodes/ANode.h"

class Conveyor {
private:
    std::vector<std::shared_ptr<ANode>> nodes;
    std::shared_ptr<Image> result;
    bool previewOn;
    int getNewId();
    bool isCyclic();
    bool DFS(std::shared_ptr<ANode>, std::set<std::shared_ptr<ANode>>);
    void putNode(std::shared_ptr<ANode> node);
public:
    Conveyor();
    ~Conveyor();

    void createNode(NodeType nodeType);
    void deleteNode(int nodeId);
    std::vector<int> getNodeIds();
    void process();
    void createConnection(int inputNodeId, int outputNodeId, int inputIndex);
    void deleteConnection(int inputNodeId, int outputNodeId);
};

#endif
