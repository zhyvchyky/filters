//
// Created by makstar on 07.12.2020.
//

#ifndef FILTERS_COLORGENERATORNODE_H
#define FILTERS_COLORGENERATORNODE_H


#include "INode.h"
#include <cassert>

class ColorGeneratorNode: public INode {
private:
    int red,green,blue, height, width;//R,G,B must fall between -255 and 255 degrees

    std::vector<std::shared_ptr<INode>> inputs;
    std::vector<std::shared_ptr<INode>> outputs;
    std::shared_ptr<Image> outputPtr;
    std::shared_ptr<Image> genColor();
public:
    void process() override;

    void setOutput(int index, std::shared_ptr<INode>) override;

    void setInput(int index, std::shared_ptr<INode>) override;

    std::vector<std::shared_ptr<INode>> getInputs() override;

    void setColorValues(int colorRed, int colorGreen, int colorBlue, int h, int w);

    std::shared_ptr<Image> getOutputPtr() override;

    std::tuple<int, int, int, int ,int> getColorValues();
};


#endif //FILTERS_COLORGENERATORNODE_H
