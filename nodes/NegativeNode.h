//
// Created by linups on 12/19/20.
//

#ifndef FILTERS_NEGATIVENODE_H
#define FILTERS_NEGATIVENODE_H
#include "INode.h"


class NegativeNode: public INode {
private:
    std::vector<std::shared_ptr<INode>> inputs;
    std::vector<std::shared_ptr<INode>> outputs;
    std::shared_ptr<Image> outputPtr;

    std::shared_ptr<Image> applyTransform(std::shared_ptr<Image> img1);

public:
    void process() override;

    void setOutput(int index, std::shared_ptr<INode>) override;

    void setInput(int index, std::shared_ptr<INode>) override;

    std::vector<std::shared_ptr<INode>> getInputs() override;

    std::shared_ptr<Image> getOutputPtr() override;
};


#endif //FILTERS_NEGATIVENODE_H
