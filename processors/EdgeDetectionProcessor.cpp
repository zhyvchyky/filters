//
// Created by linups on 11/28/20.
//

#include "EdgeDetectionProcessor.h"

std::shared_ptr<Image> EdgeDetectionProcessor::process(Config config) {

}

std::shared_ptr<Image> EdgeDetectionProcessor::preProcess(std::shared_ptr<Image> img1) {
    auto bnw = BlackAndWhiteProcessor(50);
    img1 = bnw.applyTransform(img1);
    auto blur = GaussianBlurProcessor(2);
    img1 = blur.applyTransform(img1);
    return img1;
}

std::tuple<std::shared_ptr<Image>, int*> EdgeDetectionProcessor::calcGradient(const std::shared_ptr<Image>& img1) {
    int width = img1->getWidth();
    int height = img1->getHeight();
    auto midXVal = std::make_shared<Image>(height, width, 3, new Pixel[height*width]);
    auto midYVal = std::make_shared<Image>(height, width, 3, new Pixel[height*width]);
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            Pixel pixel1 = applyVectorTransform(img1, i, j, Horizontal, 1, kernelX1);
            Pixel pixel2 = applyVectorTransform(img1, i, j, Horizontal, 1, kernelX2);
            midXVal->setPixel(i, j, pixel1.red, pixel1.green, pixel1.blue);
            midYVal->setPixel(i, j, pixel2.red, pixel2.green, pixel2.blue);
        }
    }
    auto imgX = std::make_shared<Image>(height, width, 3, new Pixel[height*width]);
    auto imgY = std::make_shared<Image>(height, width, 3, new Pixel[height*width]);
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            Pixel pixel1 = applyVectorTransform(midXVal, i, j, Vertical, 1, kernelX2);
            Pixel pixel2 = applyVectorTransform(midYVal, i, j, Vertical, 1, kernelX1);
            imgX->setPixel(i, j, pixel1.red, pixel1.green, pixel1.blue);
            imgY->setPixel(i, j, pixel2.red, pixel2.green, pixel2.blue);
        }
    }
    midXVal.reset();
    midYVal.reset();
    std::shared_ptr<Image> gradient = calcHypotenuse(imgX, imgY);
    int* angle = calcAtan2(imgX, imgY);
    imgX.reset();
    imgY.reset();
    return std::make_tuple(gradient, angle);
}

std::shared_ptr<Image> EdgeDetectionProcessor::calcHypotenuse(const std::shared_ptr<Image>& imgX, const std::shared_ptr<Image>& imgY) {
    int width = imgX->getWidth();
    int height = imgY->getHeight();
    auto result = std::make_shared<Image>(height, width, 3, new Pixel[height*width]);
    int max = 0;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            Pixel pixel1 = imgX->getPixel(i, j);
            Pixel pixel2 = imgY->getPixel(i, j);

            int xVal = pixel1.red;
            int yVal = pixel2.red;

            int resultVal = ceil(sqrt(pow(xVal, 2) + pow(yVal, 2)));
            if(max < resultVal){
                max = resultVal;
            }
            result->setPixel(i, j, resultVal, resultVal, resultVal);
        }
    }
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            Pixel pixel1 = result->getPixel(i, j);
            pixel1 = pixel1 * (255./double(max));
            result->setPixel(i, j, pixel1.red, pixel1.green, pixel1.blue);
        }
    }
    return result;
}

int* EdgeDetectionProcessor::calcAtan2(const std::shared_ptr<Image> &imgX, const std::shared_ptr<Image> &imgY) {
    int width = imgX->getWidth();
    int height = imgY->getHeight();
    int* result = new int[height*width];
    const double pi = 3.1428;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            Pixel pixel1 = imgX->getPixel(i, j);
            Pixel pixel2 = imgY->getPixel(i, j);

            double xVal = pixel1.red;
            double yVal = pixel2.red;

            double degreeVal = atan(yVal/xVal) * 180./pi;
            if((0 <= degreeVal && degreeVal < 22.5) || (157.5 <= degreeVal && degreeVal <= 180)){
                result[i*width + j] = 0;
            }
            else if(22.5 <= degreeVal && degreeVal < 67.5){
                result[i*width + j] = 45;
            }
            else if(67.5 <= degreeVal && degreeVal < 112.5){
                result[i*width + j] = 90;
            }
            else if(112.5 <= degreeVal && degreeVal < 157.5){
                result[i*width + j] = 135;
            }
        }
    }
    return result;
}