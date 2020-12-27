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

    auto new_img = std::make_shared<Image>(height, width, 3, new Pixel[height * width]);
    int grey; // max, min;
    Pixel current;

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            current = img->getPixel(i, j);
            grey = (current.red + current.green + current.blue) / 3;
            new_img->setPixel(i, j, grey, grey, grey);
        }
    }
    return new_img;
}

NodeType BlackAndWhiteNode::getNodeType() {
    return NodeType::BlackAndWhiteNode;
}
