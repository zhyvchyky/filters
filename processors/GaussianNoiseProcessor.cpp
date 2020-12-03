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

double* GaussianNoiseProcessor::genNormDist(const std::shared_ptr<Image>& img1) {
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
    if((width*height) % 2 != 0){
        double uOne = double(rand()) / RAND_MAX;
        double uTwo = double(rand()) / RAND_MAX;
        weights[width*height-1] = sqrt(noise) * sqrt(-2 * log(uOne)) * cos(2 * pi * uTwo) + brightness;
    }
    return weights;
}

std::shared_ptr<Image> GaussianNoiseProcessor::applyTransform(std::shared_ptr<Image> img1) {
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
