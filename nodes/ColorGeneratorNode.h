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

    void setColorValues(int red, int green, int blue);

    std::shared_ptr<Image> getOutputPtr() override;

    std::tuple<int, int, int> getColorValues();
};


#endif //FILTERS_COLORGENERATORNODE_H
