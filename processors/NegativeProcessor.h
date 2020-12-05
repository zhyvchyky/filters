//
// Created by linups on 12/5/20.
//

#ifndef FILTERS_NEGATIVEPROCESSOR_H
#define FILTERS_NEGATIVEPROCESSOR_H
#include "IProcessor.h"


class NegativeProcessor: IProcessor {
public:
    std::shared_ptr<Image> process(Config config) override;
    std::shared_ptr<Image> applyTransform(std::shared_ptr<Image> img1);
};


#endif //FILTERS_NEGATIVEPROCESSOR_H
