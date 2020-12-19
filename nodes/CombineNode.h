//
// Created by linups on 12/19/20.
//

#ifndef FILTERS_COMBINENODE_H
#define FILTERS_COMBINENODE_H
#include "INode.h"


class CombineNode: public INode {
private:
    std::vector<std::shared_ptr<INode>> inputs;
    std::vector<std::shared_ptr<INode>> outputs;
    std::shared_ptr<Image> outputPtr;

    std::shared_ptr<Image> combine(const std::shared_ptr<Image>& img1, const std::shared_ptr<Image>& img2);

public:
    void process() override;

    void setOutput(int index, std::shared_ptr<INode>) override;

    void setInput(int index, std::shared_ptr<INode>) override;

    std::shared_ptr<Image> getOutputPtr() override;
};


#endif //FILTERS_COMBINENODE_H
