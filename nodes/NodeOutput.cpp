//
// Created by noxin on 11/30/20.
//

#include "NodeOutput.h"

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

std::vector<std::variant<int, std::string>> NodeOutput::getFields() {
    return std::vector<std::variant<int, std::string>>();
}

void NodeOutput::setFields(std::vector<std::variant<int, std::string>> fields) {
    assert(!fields.empty() && "Vector should hold 1 field");
    assert(fields[0].index() == 1 && "Field should be string");
    this->filePath = std::get<std::string>(fields[0]);
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
