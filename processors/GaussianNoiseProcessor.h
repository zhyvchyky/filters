//
// Created by linups on 12/3/20.
//

#ifndef FILTERS_GAUSSIANNOISEPROCESSOR_H
#define FILTERS_GAUSSIANNOISEPROCESSOR_H
#include <iostream>
#include <cmath>
#include "IProcessor.h"


class GaussianNoiseProcessor: IProcessor {
private:
    int brightness;
    int noise;
public:
    GaussianNoiseProcessor(int brightness, int noise);

    std::shared_ptr<Image> process(Config config) override;
    double* genNormDist(std::shared_ptr<Image> img1);
};


#endif //FILTERS_GAUSSIANNOISEPROCESSOR_H
