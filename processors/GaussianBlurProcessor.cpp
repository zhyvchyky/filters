//
// Created by linups on 11/21/20.
//

#include "GaussianBlurProcessor.h"
#include "utilities/applyVectorTransform.h"

GaussianBlurProcessor::GaussianBlurProcessor(int N) {
    //TODO raise error if N(radius of blur) > 100 or N <= 0
    this->N = N;
}

std::shared_ptr<Image> GaussianBlurProcessor::process(Config config) {     //розраховує gaussian kernel

}

double* GaussianBlurProcessor::calcWeights() {       //розраховує gaussian kernel
    auto weights = new double[2*N+1];
    weights[N] = 1.;                //додамо до масиву вагу центрального елементу
    double scale = 1.;                                 //також додамо значення центрального елементу

    for(int weight = 1; weight < N+1; ++weight){
        double x = 3. * double (weight)/double (N);         //розраховуємо опорні точки
        double Gval = exp(-x * x/2.);                   //розраховуємо значення функції в опорних точках
        weights[N + weight] = weights[N - weight] = Gval;   //kernel симетричний тому однакові значення будуть на симетричних позиціях
        scale += 2. * Gval;
    }

    for(int i = 0; i < 2*N + 1; i++){
        weights[i] /= scale;                    //нормуємо розраховані вагові значення
    }
    return weights;
}

std::shared_ptr<Image> GaussianBlurProcessor::applyTransform(const std::shared_ptr<Image>& img1) {  //застосовуємо фільтр як композицію двох: по вісі х і по вісі у
    int width = img1->getWidth();
    int height = img1->getHeight();
    double* weights = calcWeights();
    std::shared_ptr<Image> img2 = std::make_shared<Image>(height, width, 3, new Pixel[height * width]);

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            Pixel pixel = applyVectorTransform(img1, i, j, Horizontal, N, weights);
            img2->setPixel(i, j, pixel.red, pixel.green, pixel.blue);
        }
    }

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            Pixel pixel = applyVectorTransform(img2, i, j, Vertical, N, weights);
            img1->setPixel(i, j, pixel.red, pixel.green, pixel.blue);
        }
    }
    return img1;
}

