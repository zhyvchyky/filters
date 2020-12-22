//
// Created by linups on 12/19/20.
//

#include "CombineNode.h"

void CombineNode::process() {
    this->outputPtr = combine(this->inputs[0]->getOutputPtr(), this->inputs[1]->getOutputPtr());
}

std::shared_ptr<Image> CombineNode::combine(std::shared_ptr<Image> img1, std::shared_ptr<Image> img2) {
    //TODO exception if dimensions mismatch
    int height = img1->getHeight();
    int width = img1->getWidth();
    std::shared_ptr<Image> result = std::make_shared<Image>(height, width, 3, new Pixel[height*width]);

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            Pixel pixel1 = img1->getPixel(i,j);
            Pixel pixel2 = img2->getPixel(i,j);
            result->setPixel(i, j, (pixel1.red + pixel2.red) / 2, (pixel1.green + pixel2.green) / 2, (pixel1.blue + pixel2.blue) / 2);
        }
    }
    return result;
}

void CombineNode::setInput(int index, std::shared_ptr<ANode> node) {
    if(this->inputs.size() <= index)
        this->inputs.push_back(node);
    else
        this->inputs[index] = node;
}

