//
// Created by makstar on 23.11.2020.
//

#ifndef FILTERS_BLACKANDWHITEPROCESSOR_H
#define FILTERS_BLACKANDWHITEPROCESSOR_H

#include "IProcessor.h"
#include "Image.h"

class BlackAndWhiteProcessor: public IProcessor {
private:
    int scale;
public:
    explicit BlackAndWhiteProcessor(int scale);
    std::shared_ptr<Image> process(Config config) override;
    std::shared_ptr<Image> applyTransform(const std::shared_ptr<Image>& img);
};


#endif //FILTERS_BLACKANDWHITEPROCESSOR_H
