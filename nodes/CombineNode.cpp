//
// Created by linups on 12/19/20.
//

#include "CombineNode.h"

void CombineNode::process() {
    this->outputPtr = combine(this->inputs[0]->getOutputPtr(), this->inputs[1]->getOutputPtr());
}

std::shared_ptr<Image> CombineNode::combine(const std::shared_ptr<Image>& img1, const std::shared_ptr<Image>& img2) {
    int height = img1->getHeight();
    int width = img1->getWidth();
    std::shared_ptr<Image> result = std::make_shared<Image>(height, width, 3, new Pixel[height*width]);
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            Pixel pixel1 = img1->getPixel(i,j);
            Pixel pixel2 = img2->getPixel(i,j);
            Pixel resulting_pix = (pixel1 + pixel2) * 0.5;
            result->setPixel(i, j, resulting_pix.red, resulting_pix.green, resulting_pix.blue);
        }
    }
    return result;
}

void CombineNode::setOutput(int index, std::shared_ptr<INode> node) {
    if(this->outputs.size() <= index)
        this->outputs.push_back(node);
    else
        this->outputs[index] = node;
}

void CombineNode::setInput(int index, std::shared_ptr<INode> node) {
    if(this->inputs.size() <= index)
        this->inputs.push_back(node);
    else
        this->inputs[index] = node;
}

std::shared_ptr<Image> CombineNode::getOutputPtr() {
    return this->outputPtr;
}