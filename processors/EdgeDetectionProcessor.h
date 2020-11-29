//
// Created by linups on 11/28/20.
//

#ifndef FILTERS_EDGEDETECTIONPROCESSOR_H
#define FILTERS_EDGEDETECTIONPROCESSOR_H
#include "IProcessor.h"
#include "GaussianBlurProcessor.h"
#include "BlackAndWhiteProcessor.h"
#include "utilities/applyVectorTransform.h"
#include <cmath>
#include <tuple>


class EdgeDetectionProcessor: IProcessor {
private:
    double kernelX1[3] = {1., 0., -1.};
    double kernelX2[3] = {1., 2., 1.};

public:
    std::shared_ptr<Image> process(Config config) override;
    std::shared_ptr<Image> preProcess(std::shared_ptr<Image> img1);
    std::tuple<std::shared_ptr<Image>, int*> calcGradient(const std::shared_ptr<Image>& img1);
    std::shared_ptr<Image> calcHypotenuse(const std::shared_ptr<Image>& imgX, const std::shared_ptr<Image>& imgY);
    int* calcAtan2(const std::shared_ptr<Image>& imgX, const std::shared_ptr<Image>& imgY);
    std::shared_ptr<Image> nonMaxSupression(const std::shared_ptr<Image>& gradient, const int* angle);
};


#endif //FILTERS_EDGEDETECTIONPROCESSOR_H
