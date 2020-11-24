//
// Created by makstar on 23.11.2020.
//

#include "BlackAndWhiteProcessor.h"

BlackAndWhiteProcessor::BlackAndWhiteProcessor(int scale) {
    //TODO raise error if scale > 100 or scale < 0
    this->scale = scale;
}

void BlackAndWhiteProcessor::process() {
//    applyTransform(Image);
}

Image* BlackAndWhiteProcessor::applyTransform(Image *img) {

    int width = img->getWidth();
    int height = img->getHeight();

    Image new_img = Image(height, width, 3, new Pixel[height * width]);;
    int grey, max, min;
    Pixel current;

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            current = img->getPixel(i, j);
            max = current.getMaxPixel();
            min = current.getMinPixel();
            grey = round(min + (this->scale*(max - min)/100));
            new_img.setPixel(i, j, grey, grey, grey);
        }
    }
    return &new_img;
}
