//
// Created by noxin on 11/30/20.
//

#include "NodeInput.h"

void NodeInput::process() {
    this->outputPtr = getImageFromFile(filePath);
}

//TODO
void NodeInput::setOutput(int index, std::shared_ptr<INode> node) {
    if(this->outputs.size() <= index)
        this->outputs.push_back(node);
    else
        this->outputs[index] = node;
}

void NodeInput::setInput(int index, std::shared_ptr<INode> node) {
    throw std::invalid_argument("Impossible to set inputs for this Node");
}

//TODO remove magical value 1
void NodeInput::setFields(std::vector<std::variant<int, std::string>> fields) {
    assert(!fields.empty() && "Vector should hold 1 field");
    assert(fields[0].index() == 1 && "Field should be string");
    this->filePath = std::get<std::string>(fields[0]);
}

std::shared_ptr<Image> NodeInput::getImageFromFile(const std::string &path) {
    std::ifstream fileInput;
    fileInput.open(path);
    if (fileInput.fail())
        throw std::invalid_argument("File doesn't exist");
    fileInput.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        auto[mode, width, height, maxColorNumber] = getHeader(fileInput);
        auto *matrix = new Pixel[width * height];
        int red;
        int green;
        int blue;

        //TODO implement comment ignoring
        for (int i = 0; i < height * width; i++) {
            fileInput >> red;
            fileInput >> green;
            fileInput >> blue;
            matrix[i].setColors(red, green, blue);
        }
        fileInput.close();
        return std::make_shared<Image>(Image(height, width, maxColorNumber, matrix));
    } catch (const std::ifstream::failure &e) {
        throw std::invalid_argument("Bad file");
    }
}

std::tuple<int, int, int, int> NodeInput::getHeader(std::ifstream &input) {
    try {
        std::optional<int> mode;
        std::optional<int> width;
        std::optional<int> height;
        std::optional<int> maxColorNumber;
        std::string word;
        while (input >> word) {
            if (word[0] == '#') {
                input.ignore(std::numeric_limits<std::streamsize>::max(), input.widen('\n'));
            } else {
                if (!mode)
                    mode = word[1] - '0';
                else if (!width)
                    width = std::stoi(word);
                else if (!height) {
                    height = std::stoi(word);
                } else if (!maxColorNumber) {
                    maxColorNumber = std::stoi(word);
                    break;
                }
            }
        }
        return {mode.value(), width.value(), height.value(), maxColorNumber.value()};
    } catch (const std::ifstream::failure &e) {
        throw e;
    }
}

std::vector<std::variant<int, std::string>> NodeInput::getFields() {
    return std::vector<std::variant<int, std::string>>();
}

std::shared_ptr<Image> NodeInput::getOutputPtr() {
    return this->outputPtr;
}
