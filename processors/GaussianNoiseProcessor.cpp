//
// Created by linups on 12/3/20.
//

#include "GaussianNoiseProcessor.h"

GaussianNoiseProcessor::GaussianNoiseProcessor(int brightness, int noise) {
    //TODO raise error if noise <= 0
    this->brightness = brightness;
    this->noise = noise;
}

std::shared_ptr<Image> GaussianNoiseProcessor::process(Config config) {

}

double* GaussianNoiseProcessor::genNormDist(std::shared_ptr<Image> img1) {
    int width = img1->getWidth();
    int height = img1->getHeight();
    double const pi = 3.1428;
    auto weights = new double[height * width];

    srand(time(nullptr));
    for(int i = 0; i < height * width; i+=2){
        double uOne = double(rand()) / RAND_MAX;
        double uTwo = double(rand()) / RAND_MAX;
        weights[i] = sqrt(noise) * sqrt(-2 * log(uOne)) * cos(2 * pi * uTwo) + brightness;
        weights[i+1] = sqrt(noise) * sqrt(-2 * log(uTwo)) * cos(2 * pi * uOne) + brightness;
    }
    if((width*height) % 2 == 0){
        double uOne = double(rand()) / RAND_MAX;
        double uTwo = double(rand()) / RAND_MAX;
        weights[width*height-1] = sqrt(noise) * sqrt(-2 * log(uOne)) * cos(2 * pi * uTwo) + brightness;
    }
    return weights;
}
