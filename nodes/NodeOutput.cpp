//
// Created by noxin on 11/30/20.
//

#include "NodeOutput.h"

#include <utility>

void NodeOutput::process() {
    if (this->inputs.empty()){
        writeImageToFile(std::make_shared<Image>(0, 0, 255, new Pixel[0]), this->filePath);
    }
    else {
        writeImageToFile(this->inputs[0]->getOutputPtr(), this->filePath);
        this->outputPtr = this->inputs[0]->getOutputPtr();

    }
}


void NodeOutput::writeImageToFile(std::shared_ptr<Image> image, const std::string path) {
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

void NodeOutput::setFilePath(std::string filepath) {
    this->filePath = std::move(filepath);
    notify();
}

std::string  NodeOutput::getFilePath() {
    return this->filePath;
}

NodeType NodeOutput::getNodeType() {
    return NodeType::NodeOutput;
}
