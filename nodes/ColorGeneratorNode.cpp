//
// Created by makstar on 07.12.2020.
//

#include "ColorGeneratorNode.h"

void ColorGeneratorNode::process() {
    this->outputPtr = applyTransform(this->inputs[0]->getOutputPtr());
}

std::shared_ptr<Image> ColorGeneratorNode::applyTransform(const std::shared_ptr<Image>& img) {

    int width = img->getWidth();
    int height = img->getHeight();

    std::shared_ptr<Image> new_img = std::make_shared<Image>(Image(height, width, 3, new Pixel[height * width]));

    Pixel current;

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            current = img->getPixel(i, j);
            current.red = addToColor(current.red, this->r);
            current.green = addToColor(current.green, this->g);
            current.blue = addToColor(current.blue, this->b);

            new_img->setPixel(i, j, current.red, current.green, current.blue);
        }
    }
    return new_img;
}

int ColorGeneratorNode::addToColor(int p1, int p2){
    p1 += p2;
    if(p1 > 255) p1 = 255;
    else if(p1 < 0) p1 = 0;
    return p1;
}

void ColorGeneratorNode::setOutput(int index, std::shared_ptr<INode> node) {
    if(this->outputs.size() <= index)
        this->outputs.push_back(node);
    else
        this->outputs[index] = node;
}

void ColorGeneratorNode::setInput(int index, std::shared_ptr<INode> node) {
    if(this->inputs.size() <= index)
        this->inputs.push_back(node);
    else
        this->inputs[index] = node;
}

std::shared_ptr<Image> ColorGeneratorNode::getOutputPtr() {
    return this->outputPtr;
}

void ColorGeneratorNode::setColorValues(int red, int green, int blue) {
    this->r = red;
    this->g = green;
    this->b = blue;
}

std::tuple<int, int, int> ColorGeneratorNode::getColorValues() {
    return std::make_tuple(this->r, this->g, this->b);
}