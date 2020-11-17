//
// Created by noxin on 11/17/20.
//


#include "ImageSourceProcessor.h"


void ImageSourceProcessor::process() {

}

std::optional<Image> ImageSourceProcessor::getImageFromFile(const std::string &path) {
    std::ifstream fileInput(path);
    if (fileInput.fail()) {
        std::cerr << "Failed to read file;\n";
        return {};
    }
    auto[mode, width, height, maxColorNumber] = getHeader(fileInput);
    auto *matrix = new Pixel[width * height];
    int red;
    int green;
    int blue;

    //TODO comment ignoring
    for (int i = 0; i < height * width; i++) {
        if (!(fileInput >> red) || !(fileInput >> green) || !(fileInput >> blue)) {
            std::cerr << "Failed to read pixel from the file" << std::endl;
            fileInput.close();
            return {};
        }
        matrix[i].setColors(red, green, blue);
    }
    fileInput.close();
    return {Image(height, width, maxColorNumber, matrix)};
}

//TODO add error handling
std::tuple<int, int, int, int> ImageSourceProcessor::getHeader(std::ifstream &input) {
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
}
