//
// Created by makstar on 01.12.2020.
//

#ifndef FILTERS_BLACKANDWHITENODE_H
#define FILTERS_BLACKANDWHITENODE_H

#include "INode.h"
#include <cassert>

class BlackAndWhiteNode: public INode {
private:
    int power;//power must fall between 0 and 100

    std::vector<std::shared_ptr<INode>> inputs;
    std::vector<std::shared_ptr<INode>> outputs;
    std::shared_ptr<Image> outputPtr;

    std::shared_ptr<Image> applyTransform(const std::shared_ptr<Image>&);
public:
    void process() override;

    void setOutput(int index, std::shared_ptr<INode>) override;

    void setInput(int index, std::shared_ptr<INode>) override;

    void setPower(int pwr);

    int getPower();

    std::shared_ptr<Image> getOutputPtr() override;
};


#endif //FILTERS_BLACKANDWHITENODE_H
