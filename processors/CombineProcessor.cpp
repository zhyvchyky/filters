//
// Created by linups on 12/18/20.
//

#include "CombineProcessor.h"
std::shared_ptr<Image> CombineProcessor::process(Config config) {

}

std::shared_ptr<Image> CombineProcessor::combine(const std::shared_ptr<Image>& img1, const std::shared_ptr<Image>& img2) {
    int height = img1->getHeight();
    int width = img1->getWidth();
    std::shared_ptr<Image> result = std::make_shared<Image>(height, width, 3, new Pixel[height*width]);
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            Pixel pixel1 = img1->getPixel(i,j);
            Pixel pixel2 = img2->getPixel(i,j);
            Pixel resulting_pix = (pixel1 + pixel2) * 0.5;
            result->setPixel(i, j, resulting_pix.red, resulting_pix.green, resulting_pix.blue);
        }
    }
    return result;
}
