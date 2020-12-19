//
// Created by linups on 12/19/20.
//

#ifndef FILTERS_EDGEDETECTIONNODE_H
#define FILTERS_EDGEDETECTIONNODE_H
#include "INode.h"
#include "BlackAndWhiteNode.h"
#include "GaussianBlurNode.h"


class EdgeDetectionNode: public INode {
private:
    double kernelX1[3] = {1., 0., -1.};
    double kernelX2[3] = {1., 2., 1.};

    std::vector<std::shared_ptr<INode>> inputs;
    std::vector<std::shared_ptr<INode>> outputs;
    std::shared_ptr<Image> outputPtr;

    std::shared_ptr<Image> preProcess(std::shared_ptr<Image> img1);
    std::tuple<std::shared_ptr<Image>, int*> calcGradient(const std::shared_ptr<Image>& img1);
    std::shared_ptr<Image> calcHypotenuse(const std::shared_ptr<Image>& imgX, const std::shared_ptr<Image>& imgY);
    int* calcAtan2(const std::shared_ptr<Image>& imgX, const std::shared_ptr<Image>& imgY);
    std::shared_ptr<Image> nonMaxSupression(const std::shared_ptr<Image>& gradient, const int* angle);
    std::shared_ptr<Image> dThresholdEdgeDetector(const std::shared_ptr<Image>& supressedImg);

    std::shared_ptr<Image> applyTransform(std::shared_ptr<Image> image);

public:
    void process() override;

    void setOutput(int index, std::shared_ptr<INode>) override;

    void setInput(int index, std::shared_ptr<INode>) override;

    std::shared_ptr<Image> getOutputPtr() override;
};

#endif //FILTERS_EDGEDETECTIONNODE_H
