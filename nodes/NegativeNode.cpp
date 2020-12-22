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
    auto result = std::make_shared<Image>(height, width, 3, new Pixel[height*width]);

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            Pixel pixel = img1->getPixel(i, j);
            result->setPixel(i, j, -(pixel.red + maxInvertValue), -(pixel.green + maxInvertValue), -(pixel.blue + maxInvertValue));
        }
    }
    return result;
}
