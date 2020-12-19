//
// Created by linups on 12/18/20.
//

#ifndef FILTERS_COMBINEPROCESSOR_H
#define FILTERS_COMBINEPROCESSOR_H
#include "IProcessor.h"


class CombineProcessor: IProcessor {
public:
    std::shared_ptr<Image> process(Config config) override;

    std::shared_ptr<Image> combine(const std::shared_ptr<Image>& img1, const std::shared_ptr<Image>& img2);
};


#endif //FILTERS_COMBINEPROCESSOR_H
