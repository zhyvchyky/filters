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
#include "ISubject.h"

class Conveyor: public ISubject<Conveyor> {
private:
    std::map<size_t, std::shared_ptr<ANode>> nodes;
    IdGenerator idGenerator;
    bool isCyclic();
    bool DFS(std::shared_ptr<ANode>, std::set<std::shared_ptr<ANode>>);
    size_t createNode(NodeType nodeType);
    void deleteNode(size_t nodeId);
    void createConnection(size_t inputNodeId, size_t outputNodeId);
    void deleteConnection(size_t inputNodeId, size_t outputNodeId);
    void process();
public:
    Conveyor();
    std::map<size_t, std::shared_ptr<ANode>> getNodes();
    friend class CreateNodeCommand;
    friend class DeleteNodeCommand;
    friend class CreateConnectionCommand;
    friend class DeleteConnectionCommand;
    friend class ProcessCommand;
    friend class SetColorGeneratorCommand;
    friend class SetGaussianBlurCommand;
    friend class SetGaussianNoiseCommand;
    friend class SetMedianCommand;
    friend class SetNodeInputCommand;
    friend class SetNodeOutputCommand;
    friend class AttachGaussianBlurCommand;
    friend class AttachInputCommand;
    friend class AttachOutputCommand;
    friend class AttachMedianCommand;
    friend class AttachGaussianNoiseCommand;
    friend class AttachColorGeneratorCommand;
    friend class DeattachGaussianBlurCommand;
    friend class DeattachInputCommand;
    friend class DeattachOutputCommand;
    friend class DeattachMedianCommand;
    friend class DeattachGaussianNoiseCommand;
    friend class DeattachColorGeneratorCommand;
};

#endif
