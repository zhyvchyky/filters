//
// Created by linups on 12/5/20.
//

#include "NegativeProcessor.h"

std::shared_ptr<Image> NegativeProcessor::process(Config config) {

}

std::shared_ptr<Image> NegativeProcessor::applyTransform(std::shared_ptr<Image> img1) {
    const int maxInvertValue = -255;
    int height = img1->getHeight();
    int width = img1->getWidth();

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            Pixel pixel = img1->getPixel(i, j);
            pixel = pixel + maxInvertValue;
            pixel = pixel * (-1);
            img1->setPixel(i, j, pixel.red, pixel.green, pixel.blue);
        }
    }
    return img1;
}
