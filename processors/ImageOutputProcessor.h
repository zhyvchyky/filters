//
// Created by noxin on 11/24/20.
//

#ifndef FILTERS_IMAGEOUTPUTPROCESSOR_H
#define FILTERS_IMAGEOUTPUTPROCESSOR_H

#include <memory>
#include <fstream>
#include "IProcessor.h"
#include "Image.h"

class ImageOutputProcessor : IProcessor {
public:
    void process() override;
    void writeImageToFile(std::shared_ptr<Image> image);
    void writeImageToFile(std::shared_ptr<Image> image, const std::string &path);
};


#endif //FILTERS_IMAGEOUTPUTPROCESSOR_H
