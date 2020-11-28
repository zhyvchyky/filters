//
// Created by linups on 11/21/20.
//

#ifndef FILTERS_GAUSSIANBLURPROCESSOR_H
#define FILTERS_GAUSSIANBLURPROCESSOR_H
#include "IProcessor.h"
#include "Image.h"
#include <vector>
#include <bits/stdc++.h>
#include <cmath>

class GaussianBlurProcessor: IProcessor {
private:
    int N;
public:

    explicit GaussianBlurProcessor(int N);
    std::shared_ptr<Image> process(Config config) override;

    void applyTransform(const std::shared_ptr<Image>& img1) const;
    double* calcWeights() const;
};


#endif //FILTERS_GAUSSIANBLURPROCESSOR_H
