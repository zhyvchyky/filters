//
// Created by noxin on 11/24/20.
//

#include "ImageOutputProcessor.h"
#include "Node.h"

std::shared_ptr<Image> ImageOutputProcessor::process(Config config) {
    writeImageToFile(config.inputs[0]->outputPointer, std::get<std::string>(config.fields[0]));
    return nullptr;
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

void ImageOutputProcessor::writeImageToFile(std::shared_ptr<Image> image) {

}
