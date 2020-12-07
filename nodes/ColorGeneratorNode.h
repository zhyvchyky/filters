//
// Created by makstar on 07.12.2020.
//

#ifndef FILTERS_COLORGENERATORNODE_H
#define FILTERS_COLORGENERATORNODE_H


#include "INode.h"
#include <cassert>

class ColorGeneratorNode: public INode {
private:
    int r,g,b;//R,G,B must fall between -255 and 255 degrees

    std::vector<std::shared_ptr<INode>> inputs;
    std::vector<std::shared_ptr<INode>> outputs;
    std::shared_ptr<Image> outputPtr;
    std::shared_ptr<Image> applyTransform(const std::shared_ptr<Image>&);
    int addToColor(int, int);
public:
    void process() override;

    void setOutput(int index, std::shared_ptr<INode>) override;

    void setInput(int index, std::shared_ptr<INode>) override;

    void setFields(std::vector<std::variant<int, std::string>>) override;

    std::shared_ptr<Image> getOutputPtr() override;

    std::vector<std::variant<int, std::string>> getFields() override;
};


#endif //FILTERS_COLORGENERATORNODE_H
