//
// Created by makstar on 07.12.2020.
//

#include "ColorGeneratorNode.h"

void ColorGeneratorNode::process() {
    this->outputPtr = genColor();
}

std::shared_ptr<Image> ColorGeneratorNode::genColor() {
    auto new_img = std::make_shared<Image>(height, width, 3, new Pixel[height * width]);

    Pixel pixel1(this->red, this->green, this->blue);

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            new_img->setPixel(i, j, pixel1.red, pixel1.green, pixel1.blue);
        }
    }
    return new_img;
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

void ColorGeneratorNode::setColorValues(int colorRed, int colorGreen, int colorBlue, int h, int w) {
    this->red = colorRed;
    this->green = colorGreen;
    this->blue = colorBlue;
    this->height = h;
    this->width = w;
}

std::tuple<int, int, int, int, int> ColorGeneratorNode::getColorValues() {
    return std::make_tuple(this->red, this->green, this->blue, this->height, this->width);
}