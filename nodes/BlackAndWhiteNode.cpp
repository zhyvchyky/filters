//
// Created by makstar on 01.12.2020.
//

#include "BlackAndWhiteNode.h"


void BlackAndWhiteNode::process() {
    this->outputPtr = applyTransform(this->inputs[0]->getOutputPtr());
}

std::shared_ptr<Image> BlackAndWhiteNode::applyTransform(const std::shared_ptr<Image>& img) {

    int width = img->getWidth();
    int height = img->getHeight();

    std::shared_ptr<Image> new_img = std::make_shared<Image>(Image(height, width, 3, new Pixel[height * width]));
    int grey, max, min;
    Pixel current;

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            current = img->getPixel(i, j);
            max = current.getMaxPixel();
            min = current.getMinPixel();
            grey = round(min + (this->power*(max - min)/100));
            new_img->setPixel(i, j, grey, grey, grey);
        }
    }
    return new_img;
}

void BlackAndWhiteNode::setOutput(int index, std::shared_ptr<INode> node) {
    if(this->outputs.size() <= index)
        this->outputs.push_back(node);
    else
        this->outputs[index] = node;
}

void BlackAndWhiteNode::setInput(int index, std::shared_ptr<INode> node) {
    if(this->inputs.size() <= index)
        this->inputs.push_back(node);
    else
        this->inputs[index] = node;
}

std::shared_ptr<Image> BlackAndWhiteNode::getOutputPtr() {
    return this->outputPtr;
}

void BlackAndWhiteNode::setPower(int pwr) {
    this->power = pwr;
}

int BlackAndWhiteNode::getPower() {
    return this->power;
}