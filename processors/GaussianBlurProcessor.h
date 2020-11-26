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
    double scale = 0;
    std::vector<double> oneDimTransform;
public:
    enum Mode {Horizontal, Vertical};

    explicit GaussianBlurProcessor(int N);
    std::shared_ptr<Image> process(Config config) override;

    void applyTransform(Image img1);
    Pixel calculatePixel(Image img1, int row, int col, GaussianBlurProcessor::Mode mode);
};


#endif //FILTERS_GAUSSIANBLURPROCESSOR_H
