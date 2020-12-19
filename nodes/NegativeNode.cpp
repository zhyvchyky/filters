//
// Created by linups on 12/19/20.
//

#include "NegativeNode.h"

void NegativeNode::process() {
    this->outputPtr = applyTransform(this->inputs[0]->getOutputPtr());
}

std::shared_ptr<Image> NegativeNode::applyTransform(std::shared_ptr<Image> img1) {
    const int maxInvertValue = -255;
    int height = img1->getHeight();
    int width = img1->getWidth();

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            Pixel pixel = img1->getPixel(i, j);
            pixel = pixel + maxInvertValue;
            pixel = pixel * (-1);
            img1->setPixel(i, j, pixel.red, pixel.green, pixel.blue);
        }
    }
    return img1;
}

void NegativeNode::setOutput(int index, std::shared_ptr<INode> node) {
    if(this->outputs.size() <= index)
        this->outputs.push_back(node);
    else
        this->outputs[index] = node;
}

void NegativeNode::setInput(int index, std::shared_ptr<INode> node) {
    if(this->inputs.size() <= index)
        this->inputs.push_back(node);
    else
        this->inputs[index] = node;
}

std::shared_ptr<Image> NegativeNode::getOutputPtr() {
    return this->outputPtr;
}