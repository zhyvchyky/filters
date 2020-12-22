//
// Created by linups on 12/19/20.
//

#include "GaussianBlurNode.h"
void GaussianBlurNode::process() {
    this->outputPtr = applyTransform(this->inputs[0]->getOutputPtr());
}

double* GaussianBlurNode::calcWeights() {
    auto weights = new double[2*N+1];
    weights[N] = 1.;
    double scale = 1.;

    for(int weight = 1; weight < N+1; ++weight){
        double x = 3. * double (weight)/double (N);
        double Gval = exp(-x * x/2.);
        weights[N + weight] = weights[N - weight] = Gval;
        scale += 2. * Gval;
    }

    for(int i = 0; i < 2*N + 1; i++){
        weights[i] /= scale;
    }
    return weights;
}

std::shared_ptr<Image> GaussianBlurNode::applyTransform(const std::shared_ptr<Image> &img1) {
    int width = img1->getWidth();
    int height = img1->getHeight();
    double* weights = calcWeights();
    auto img2 = std::make_shared<Image>(height, width, 3, new Pixel[height * width]);
    auto img3 = std::make_shared<Image>(height, width, 3, new Pixel[height * width]);

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            Pixel pixel = applyVectorTransform(img1, i, j, Horizontal, N, weights);
            pixel = regulatePixel(pixel);
            img2->setPixel(i, j, pixel.red, pixel.green, pixel.blue);
        }
    }

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            Pixel pixel = applyVectorTransform(img2, i, j, Vertical, N, weights);
            pixel = regulatePixel(pixel);
            img3->setPixel(i, j, pixel.red, pixel.green, pixel.blue);
        }
    }
    return img3;
}

void GaussianBlurNode::setRadius(int radius) {
    this->N = radius;
}

int GaussianBlurNode::getRadius() const {
    return this->N;
}

Pixel GaussianBlurNode::regulatePixel(Pixel pxl) {
    if(pxl.red > 255){pxl.red = 255;}
    if(pxl.green > 255){pxl.green = 255;}
    if(pxl.blue > 255){pxl.blue = 255;}
    return pxl;
}