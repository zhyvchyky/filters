//
// Created by linups on 12/19/20.
//

#include "GaussianNoiseNode.h"

void GaussianNoiseNode::process() {
    this->outputPtr = genNormDist();
}

std::shared_ptr<Image> GaussianNoiseNode::genNormDist() {
    double const pi = 3.1428;
    auto arr = new Pixel[height*width];

    srand(time(nullptr));
    for(int i = 0; i < height * width; i+=2){
        double uOne = double(rand()) / RAND_MAX;
        double uTwo = double(rand()) / RAND_MAX;

        int weight1 = ceil(sqrt(noise) * sqrt(-2 * log(uOne)) * cos(2 * pi * uTwo));
        int weight2 = ceil(sqrt(noise) * sqrt(-2 * log(uTwo)) * cos(2 * pi * uOne));

        arr[i].setColors(abs(weight1), abs(weight1), abs(weight1));
        arr[i+1].setColors(abs(weight2), abs(weight2), abs(weight2));
    }
    if((width*height) % 2 != 0){
        double uOne = double(rand()) / RAND_MAX;
        double uTwo = double(rand()) / RAND_MAX;

        int weight1 = ceil(sqrt(noise) * sqrt(-2 * log(uOne)) * cos(2 * pi * uTwo));
        arr[height*width-1].setColors(abs(weight1), abs(weight1), abs(weight1));
    }
    return std::make_shared<Image>(height, width, 3, arr);
}

void GaussianNoiseNode::setNoise(int ns, int h, int w) {
    this->noise = ns;
    this->height = h;
    this->width = w;
}

std::tuple<int,int,int> GaussianNoiseNode::getNoise() {
    return std::make_tuple(this->noise, this->height, this->width);
}

void GaussianNoiseNode::setOutput(int index, std::shared_ptr<INode> node) {
    if(this->outputs.size() <= index)
        this->outputs.push_back(node);
    else
        this->outputs[index] = node;
}

void GaussianNoiseNode::setInput(int index, std::shared_ptr<INode> node) {
    if(this->inputs.size() <= index)
        this->inputs.push_back(node);
    else
        this->inputs[index] = node;
}

std::shared_ptr<Image> GaussianNoiseNode::getOutputPtr() {
    return this->outputPtr;
}