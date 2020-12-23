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
#include "utilities/IdGenerator.h"

class Conveyor {
private:
    std::vector<std::shared_ptr<ANode>> nodes;
    std::shared_ptr<Image> result;
    IdGenerator idGenerator;
    bool isCyclic();
    bool DFS(std::shared_ptr<ANode>, std::set<std::shared_ptr<ANode>>);
    std::shared_ptr<ANode> putNode(std::shared_ptr<ANode> node);
public:
    Conveyor();

    std::shared_ptr<ANode> createNode(NodeType nodeType);
    std::shared_ptr<ANode> getOutputNode();
    void deleteNode(size_t nodeId);
    std::vector<size_t> getNodeIds();
    void process();
    std::vector<std::shared_ptr<ANode>> getNodes();

    void createConnection(std::shared_ptr<ANode> inputNode, std::shared_ptr<ANode> outputNode);
    void deleteConnection(std::shared_ptr<ANode> inputNode, std::shared_ptr<ANode> outputNode);

};

#endif
