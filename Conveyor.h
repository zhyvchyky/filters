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
#include "utilities/IdGenerator.h"

class Conveyor {
    friend class CreateNodeCommand;
    friend class DeleteNodeCommand;
    friend class CreateConnectionCommand;
    friend class DeleteConnectionCommand;
    friend class ProcessCommand;
private:
    std::vector<std::shared_ptr<ANode>> nodes;
    std::shared_ptr<Image> result;
    IdGenerator idGenerator;
    bool isCyclic();
    bool DFS(std::shared_ptr<ANode>, std::set<std::shared_ptr<ANode>>);
    std::shared_ptr<ANode> putNode(std::shared_ptr<ANode> node);
    std::shared_ptr<ANode> createNode(NodeType nodeType);
    void deleteNode(size_t nodeId);
    void createConnection(std::shared_ptr<ANode> inputNode, std::shared_ptr<ANode> outputNode);
    void deleteConnection(std::shared_ptr<ANode> inputNode, std::shared_ptr<ANode> outputNode);
    void process();
public:
    Conveyor();

    std::shared_ptr<ANode> getOutputNode();
    std::vector<size_t> getNodeIds();
    std::vector<std::shared_ptr<ANode>> getNodes();


};

#endif
