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

void ColorGeneratorNode::setFields(std::vector<std::variant<int, std::string>> value) {
    assert(value.size()==3 && "Vector should hold 3 fields");
    assert(value[0].index() == 0 && value[1].index() == 0 && value[2].index() == 0 && "Fields should be integer");
    this->r = std::get<int>(value[0]);
    this->g = std::get<int>(value[1]);
    this->b = std::get<int>(value[2]);
}

std::shared_ptr<Image> ColorGeneratorNode::getOutputPtr() {
    return this->outputPtr;
}

std::vector<std::variant<int, std::string>> ColorGeneratorNode::getFields() {
    return std::vector<std::variant<int, std::string>>({this->r, this->g, this->b});
}
