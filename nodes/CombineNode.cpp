//      Temperature() {}

// Created by linups on 12/19/20.
//

#include "CombineNode.h"

void CombineNode::process() {
    this->outputPtr = combine();
}

std::shared_ptr<Image> CombineNode::combine() {
    //TODO exception if dimensions mismatch
    int height = this->inputs[0]->getOutputPtr()->getHeight();
    int width = this->inputs[0]->getOutputPtr()->getWidth();
    auto result = std::make_shared<Image>(height, width, 3, new Pixel[height*width]);

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            int colorRed = 0, colorGreen = 0, colorBlue = 0;
            for(int k = 0; k < this->inputs.size(); k++){
                Pixel pixel = this->inputs[k]->getOutputPtr()->getPixel(i, j);
                colorRed += pixel.red;
                colorGreen += pixel.green;
                colorBlue += pixel.blue;
            }
            result->setPixel(i, j, colorRed / this->inputs.size(), colorGreen / this->inputs.size(), colorBlue / this->inputs.size());
        }
    }
    return result;
}


void CombineNode::resetInput(std::shared_ptr<ANode> node) {
    this->inputs.erase(std::find(this->inputs.begin(), this->inputs.end(), node));
}

void CombineNode::setInput(std::shared_ptr<ANode> node) {
    this->inputs.push_back(node);
}

NodeType CombineNode::getNodeType() {
    return NodeType::CombineNode;
}
