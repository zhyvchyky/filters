//
// Created by noxin on 11/30/20.
//

#include "NodeOutput.h"

#include <utility>

void NodeOutput::process() {
    writeImageToFile(this->inputs[0]->getOutputPtr(), this->filePath);
}


//TODO consult about logic of work
void NodeOutput::setOutput(int index, std::shared_ptr<INode> node) {

}

void NodeOutput::setInput(int index, std::shared_ptr<INode> node) {
    if(this->inputs.size() <= index)
        this->inputs.push_back(node);
    else
        this->inputs[index] = node;
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

std::shared_ptr<Image> NodeOutput::getOutputPtr() {
    return this->outputPtr;
}

void NodeOutput::setFilePath(std::string filepath) {
    this->filePath = std::move(filepath);
}

std::string  NodeOutput::getFilePath() {
    return this->filePath;
}
