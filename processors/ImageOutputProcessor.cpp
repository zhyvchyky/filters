//
// Created by noxin on 11/24/20.
//

#include "ImageOutputProcessor.h"

void ImageOutputProcessor::process() {

}

void ImageOutputProcessor::writeImageToFile(std::shared_ptr<Image> image, const std::string &path) {
    std::ofstream fileOutput(path, std::ios_base::trunc);
    const std::string mode = "P3";
    //write mode
    fileOutput << mode << "\n";
    //write size
    fileOutput << image->getWidth() << " " << image->getHeight() << "\n";
    //write max value
    const int maxValue = 255;
    fileOutput << maxValue << '\n';
    for (int i = 0; i < image->getHeight(); i++) {
        for (int j = 0; j < image->getWidth(); j++) {
            fileOutput << image->getPixel(i, j) << ' ';
        }
    }
    fileOutput << '\n';
    fileOutput.close();

}