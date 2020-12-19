//
// Created by linups on 12/19/20.
//

#include "GaussianNoiseNode.h"

void GaussianNoiseNode::process() {
    this->outputPtr = applyTransform(this->inputs[0]->getOutputPtr());
}

double* GaussianNoiseNode::genNormDist(const std::shared_ptr<Image>& img1) {
    int width = img1->getWidth();
    int height = img1->getHeight();
    double const pi = 3.1428;
    auto weights = new double[height * width];

    srand(time(nullptr));
    for(int i = 0; i < height * width; i+=2){
        double uOne = double(rand()) / RAND_MAX;
        double uTwo = double(rand()) / RAND_MAX;
        weights[i] = sqrt(noise) * sqrt(-2 * log(uOne)) * cos(2 * pi * uTwo);
        weights[i+1] = sqrt(noise) * sqrt(-2 * log(uTwo)) * cos(2 * pi * uOne);
    }
    if((width*height) % 2 != 0){
        double uOne = double(rand()) / RAND_MAX;
        double uTwo = double(rand()) / RAND_MAX;
        weights[width*height-1] = sqrt(noise) * sqrt(-2 * log(uOne)) * cos(2 * pi * uTwo);
    }
    return weights;
}

std::shared_ptr<Image> GaussianNoiseNode::applyTransform(std::shared_ptr<Image> img1) {
    double* weights = genNormDist(img1);
    int height = img1->getHeight();
    int width = img1->getWidth();

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            Pixel pixel = img1->getPixel(i, j);
            pixel = pixel + weights[i*width + j];
            img1->setPixel(i, j, abs(pixel.red), abs(pixel.green), abs(pixel.blue));
        }
    }
    return img1;
}

void GaussianNoiseNode::setNoise(int ns) {
    this->noise = ns;
}

int GaussianNoiseNode::getNoise() {
    return this->noise
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