//
// Created by makstar on 23.11.2020.
//

#include "BlackAndWhiteProcessor.h"

BlackAndWhiteProcessor::BlackAndWhiteProcessor(int scale) {
    //TODO raise error if scale > 100 or scale < 0
    this->scale = scale;
}

std::shared_ptr<Image> BlackAndWhiteProcessor::process(Config config) {
//    applyTransform(Image);
}

std::shared_ptr<Image> BlackAndWhiteProcessor::applyTransform(const std::shared_ptr<Image>& img) {

    int width = img->getWidth();
    int height = img->getHeight();

    auto new_img = std::make_shared<Image>(height, width, 3, new Pixel[height * width]);
    int grey, max, min;
    Pixel current;

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            current = img->getPixel(i, j);
            max = current.getMaxPixel();
            min = current.getMinPixel();
            grey = round(min + (this->scale*(max - min)/100));
            new_img->setPixel(i, j, grey, grey, grey);
        }
    }
    return new_img;
}
