//
// Created by makstsar on 27.10.2020.
//

#include <iostream>

#include "Conveyor.h"

Conveyor::Conveyor() {
    std::cout << "Conveyor object created" << std::endl;
    this->nodes.push_back(std::make_shared<NodeOutput>());
}

Conveyor::~Conveyor() {
    std::cout << "Conveyor object deleted" << std::endl;
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

void Conveyor::putNode(std::shared_ptr<ANode> node) {
    int id = getNewId();
    if(nodes.size() == id){
        nodes.push_back(node);
    }
    else{
        nodes[id] = node;
    }
}

void Conveyor::createNode(NodeType nodeType) {
    switch (nodeType) {
        case NodeType::NodeInput:
            putNode(std::make_shared<NodeInput>());
        case NodeType::NegativeNode:
            putNode(std::make_shared<NegativeNode>());
        case NodeType::MedianNode:
            putNode(std::make_shared<MedianNode>());
        case NodeType::GaussianNoiseNode:
            putNode(std::make_shared<GaussianNoiseNode>());
        case NodeType::GaussianBlurNode:
            putNode(std::make_shared<GaussianBlurNode>());
        case NodeType::EdgeDetectionNode:
            putNode(std::make_shared<EdgeDetectionNode>());
        case NodeType::CombineNode:
            putNode(std::make_shared<CombineNode>());
        case NodeType::ColorGeneratorNode:
            putNode(std::make_shared<ColorGeneratorNode>());
        case NodeType::BlackAndWhiteNode:
            putNode(std::make_shared<BlackAndWhiteNode>());
    }
}

void Conveyor::createConnection(int inputNodeId, int outputNodeId, int inputIndex) {
    this->nodes[outputNodeId]->setInput(inputIndex, this->nodes[inputNodeId]);
    this->nodes[inputNodeId]->setOutput(inputIndex, this->nodes[outputNodeId]); //may del prev Output due to incorrect idx
    if(isCyclic()){
        std::cout << "Graph contains cycle!" << std::endl; //TODO raise some error
    }
}

void Conveyor::deleteConnection(int inputNodeId, int outputNodeId) {
    auto nodeIn = this->nodes[inputNodeId];
    auto nodeOut = this->nodes[outputNodeId];
    nodeIn->resetOutput(nodeOut);
    nodeOut->resetInput(nodeIn);
}

void Conveyor::deleteNode(int nodeId) {
    auto rmvNode = this->nodes[nodeId];
    auto inputs = rmvNode->getInputs();
    for(int i = 0; i < inputs.size(); i++){
        inputs[i]->resetOutput(rmvNode);
    }
    inputs.clear();
    this->nodes[nodeId] = nullptr;
    //TODO add NodeId to IDGenerator vector
}