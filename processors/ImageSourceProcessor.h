//
// Created by noxin on 11/17/20.
//

#ifndef FILTERS_IMAGESOURCEPROCESSOR_H
#define FILTERS_IMAGESOURCEPROCESSOR_H
#include "IProcessor.h"
#include "../Image.h"
#include <string>
#include <fstream>
#include <optional>
#include <iostream>
#include <tuple>

class ImageSourceProcessor:  IProcessor{
public:
    std::shared_ptr<Image> process(Config config) override;

//private: temp comment
    std::optional<Image> getImageFromFile(const std::string& path);
    std::tuple<int, int, int, int>getHeader(std::ifstream& input);

};


#endif //FILTERS_IMAGESOURCEPROCESSOR_H
