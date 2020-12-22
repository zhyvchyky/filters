//
// Created by makstsar on 27.10.2020.
//

#include <iostream>

#include "Conveyor.h"

Conveyor::Conveyor() {
    std::cout << "Conveyor object created" << std::endl;
    //createNode(OutputNode);
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
