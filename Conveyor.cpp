//
// Created by makstsar on 27.10.2020.
//

#include <iostream>

#include "Conveyor.h"

Conveyor::Conveyor() {
    this->nodes.push_back(std::make_shared<NodeOutput>());
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

std::shared_ptr<ANode> Conveyor::putNode(std::shared_ptr<ANode> node) {
    int id = this->idGenerator.getNewId();
    if(nodes.size() == id){
        nodes.push_back(node);
    }
    else{
        nodes[id] = node;
    }
    return node;
}

std::shared_ptr<ANode> Conveyor::createNode(NodeType nodeType) {
    switch (nodeType) {
        case NodeType::NodeInput:
            return putNode(std::make_shared<NodeInput>());
        case NodeType::NegativeNode:
            return putNode(std::make_shared<NegativeNode>());
        case NodeType::MedianNode:
            return putNode(std::make_shared<MedianNode>());
        case NodeType::GaussianNoiseNode:
            return putNode(std::make_shared<GaussianNoiseNode>());
        case NodeType::GaussianBlurNode:
            return putNode(std::make_shared<GaussianBlurNode>());
        case NodeType::EdgeDetectionNode:
            return putNode(std::make_shared<EdgeDetectionNode>());
        case NodeType::CombineNode:
            return putNode(std::make_shared<CombineNode>());
        case NodeType::ColorGeneratorNode:
            return putNode(std::make_shared<ColorGeneratorNode>());
        case NodeType::BlackAndWhiteNode:
            return putNode(std::make_shared<BlackAndWhiteNode>());
    }
}

void Conveyor::createConnection(std::shared_ptr<ANode> inputNode, std::shared_ptr<ANode> outputNode, size_t inputIndex) {
    outputNode->setInput(inputIndex, inputNode);
    inputNode->setOutput(inputIndex, outputNode);
    if(isCyclic()){
        std::cout << "Graph contains cycle!" << std::endl; //TODO raise some error
        deleteConnection(inputNode, outputNode);
    }
}

void Conveyor::deleteConnection(std::shared_ptr<ANode> nodeIn, std::shared_ptr<ANode> nodeOut) {
    nodeIn->resetOutput(nodeOut);
    nodeOut->resetInput(nodeIn);
}

void Conveyor::deleteNode(size_t nodeId) {
    auto rmvNode = this->nodes[nodeId];
    auto inputs = rmvNode->getInputs();
    for(int i = 0; i < inputs.size(); i++){
        inputs[i]->resetOutput(rmvNode);
    }
    inputs.clear();
    this->nodes[nodeId] = nullptr;
    this->idGenerator.freeId(nodeId);
}

std::shared_ptr<ANode> Conveyor::getOutputNode() {
    return this->nodes[0];
}
