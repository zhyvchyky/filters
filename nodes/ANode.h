//
// Created by noxin on 11/30/20.
//

#ifndef FILTERS_ANODE_H
#define FILTERS_ANODE_H

#include <memory>
#include <vector>
#include <variant>
#include <algorithm>
#include "Image.h"
#include "NodeType.h"

class ANode {
protected:
    std::shared_ptr<Image> outputPtr;
    std::vector<std::shared_ptr<ANode>> outputs;
    std::vector<std::shared_ptr<ANode>> inputs;
    virtual void process() = 0;
public:
    friend class Conveyor;

    virtual NodeType getNodeType() = 0;

    virtual void setOutput(std::shared_ptr<ANode> node);

    virtual void resetOutput(std::shared_ptr<ANode> node);

    virtual void setInput(std::shared_ptr<ANode> node);

    virtual void resetInput(std::shared_ptr<ANode> node);

    virtual std::shared_ptr<Image> getOutputPtr();

    virtual std::vector<std::shared_ptr<ANode>> getInputs();
    virtual std::vector<std::shared_ptr<ANode>> getOutputs();
};

inline std::shared_ptr<Image> ANode::getOutputPtr() {
    return this->outputPtr;
}

inline void ANode::setInput(std::shared_ptr<ANode> node) {
    if(this-inputs.empty()){
        this->inputs.push_back(node);
    }
}

inline void ANode::resetInput(std::shared_ptr<ANode> node) {
    this->inputs.clear();
}

inline void ANode::resetOutput(std::shared_ptr<ANode> node) {
    this->outputs.erase(std::find(this->outputs.begin(), this->outputs.end(), node));
}

inline void ANode::setOutput(std::shared_ptr<ANode> node) {
    this->outputs.push_back(node);
}

inline std::vector<std::shared_ptr<ANode>> ANode::getInputs(){
    return this->inputs;
};

inline std::vector<std::shared_ptr<ANode>> ANode::getOutputs(){
    return this->outputs;
};




#endif //FILTERS_ANODE_H
