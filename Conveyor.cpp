//
// Created by makstsar on 27.10.2020.
//

#include <iostream>

#include "Conveyor.h"

Conveyor::Conveyor() {
    this->nodes[0] = std::make_shared<NodeOutput>();
}

bool Conveyor::isCyclic() {
    std::set<std::shared_ptr<ANode>> hashset;
    return this->DFS(this->nodes[0], hashset);
}

bool Conveyor::DFS(std::shared_ptr<ANode> node, std::set<std::shared_ptr<ANode>> hashset) {
    std::vector<std::shared_ptr<ANode>> inputs = node->getInputs();
    if(inputs.empty()) return false;

    for(auto & input : inputs){
        if(hashset.find(input) == hashset.end()){
            hashset.insert(input);
            return this->DFS(input, hashset);
        }
        else{
            return true;
        }
    }
}


void Conveyor::process() {
    std::stack<std::shared_ptr<ANode>> stack;

    std::queue<std::shared_ptr<ANode>> queue;
    queue.push(this->nodes[0]);

    while(!queue.empty()){
        stack.push(queue.front());
        queue.pop();

        for(auto & input : stack.top()->getInputs())
            queue.push(input);
    }

    while(!stack.empty()){
        stack.top()->process();
        stack.pop();
    }
}

size_t Conveyor::createNode(NodeType nodeType) {
    int id = this->idGenerator.getNewId();
    switch (nodeType) {
        case NodeType::NodeInput:
            this->nodes[id] = std::make_shared<NodeInput>();
            break;
        case NodeType::NegativeNode:
            this->nodes[id] = std::make_shared<NegativeNode>();
            break;
        case NodeType::MedianNode:
            this->nodes[id] = std::make_shared<MedianNode>();
            break;
        case NodeType::GaussianNoiseNode:
            this->nodes[id] = std::make_shared<GaussianNoiseNode>();
            break;
        case NodeType::GaussianBlurNode:
            this->nodes[id] = std::make_shared<GaussianBlurNode>();
            break;
        case NodeType::EdgeDetectionNode:
            this->nodes[id] = std::make_shared<EdgeDetectionNode>();
            break;
        case NodeType::CombineNode:
            this->nodes[id] = std::make_shared<CombineNode>();
            break;
        case NodeType::ColorGeneratorNode:
            this->nodes[id] = std::make_shared<ColorGeneratorNode>();
            break;
        case NodeType::BlackAndWhiteNode:
            this->nodes[id] = std::make_shared<BlackAndWhiteNode>();
            break;
    }
    notify();
    return id;
}


void Conveyor::createConnection(size_t inputNodeId, size_t outputNodeId) {
    std::shared_ptr<ANode> inputNode = this->nodes[inputNodeId];
    std::shared_ptr<ANode> outputNode = this->nodes[outputNodeId];
    outputNode->setInput(inputNode);
    inputNode->setOutput(outputNode);
    if(isCyclic()){
        std::cout << "Graph contains cycle!" << std::endl;
        deleteConnection(inputNodeId, outputNodeId);
    }
    notify();
}

void Conveyor::deleteConnection(size_t inputNodeId, size_t outputNodeId) {
    std::shared_ptr<ANode> inputNode = this->nodes[inputNodeId];
    std::shared_ptr<ANode> outputNode = this->nodes[outputNodeId];
    inputNode->resetOutput(outputNode);
    outputNode->resetInput(inputNode);
    notify();
}

void Conveyor::deleteNode(size_t nodeId) {
    std::shared_ptr<ANode> rmvNode = this->nodes[nodeId];
    std::vector<std::shared_ptr<ANode>> inputs = rmvNode->getInputs();
    for(int i = 0; i < inputs.size(); i++){
        inputs[i]->resetOutput(rmvNode);
    }
    inputs.clear();
    this->nodes[nodeId] = nullptr;
    this->idGenerator.freeId(nodeId);
}

std::map<size_t, std::shared_ptr<ANode>> Conveyor::getNodes() {
    return this->nodes;
}
