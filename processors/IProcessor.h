//
// Created by noxin on 10/27/20.
//

#ifndef FILTERS_IPROCESSOR_H
#define FILTERS_IPROCESSOR_H

#include <memory>
#include "Image.h"
#include "Config.h"



class IProcessor{
public:
    virtual std::shared_ptr<Image> process(Config config) = 0;
};

#endif //FILTERS_IPROCESSOR_H
