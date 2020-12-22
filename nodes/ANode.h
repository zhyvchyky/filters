//
// Created by noxin on 11/30/20.
//

#ifndef FILTERS_ANODE_H
#define FILTERS_ANODE_H

#include <memory>
#include <vector>
#include <variant>
#include "Image.h"

class ANode {
protected:
    std::shared_ptr<Image> outputPtr;
    std::vector<std::shared_ptr<ANode>> outputs;
    std::vector<std::shared_ptr<ANode>> inputs;


public:

    virtual void process() = 0;

    void setOutput(int index, std::shared_ptr<ANode> node);

    void setInput(int index, std::shared_ptr<ANode> node);

    std::shared_ptr<Image> getOutputPtr();

    std::vector<std::shared_ptr<ANode>> getInputs();
    std::vector<std::shared_ptr<ANode>> getOutputs();
};

std::shared_ptr<Image> ANode::getOutputPtr() {
    return this->outputPtr;
}

void ANode::setInput(int index, std::shared_ptr<ANode> node) {
    if (index == 0)
        this->inputs[0] = node;

}

void ANode::setOutput(int index, std::shared_ptr<ANode> node) {
    if(this->outputs.size() <= index)
        this->outputs.push_back(node);
    else
        this->outputs[index] = node;
}

std::vector<std::shared_ptr<ANode>> ANode::getInputs(){
    return this->inputs;
};

std::vector<std::shared_ptr<ANode>> ANode::getOutputs(){
    return this->outputs;
};




#endif //FILTERS_ANODE_H
