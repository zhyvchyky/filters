//
// Created by linups on 12/19/20.
//

#ifndef FILTERS_GAUSSIANNOISENODE_H
#define FILTERS_GAUSSIANNOISENODE_H
#include "INode.h"

class GaussianNoiseNode: public INode {
private:
    int noise;

    std::vector<std::shared_ptr<INode>> inputs;
    std::vector<std::shared_ptr<INode>> outputs;
    std::shared_ptr<Image> outputPtr;

    double* genNormDist(const std::shared_ptr<Image>& img1);
    std::shared_ptr<Image> applyTransform(std::shared_ptr<Image> img1);

public:
    void process() override;

    void setOutput(int index, std::shared_ptr<INode>) override;

    void setInput(int index, std::shared_ptr<INode>) override;

    void setNoise(int ns);

    std::shared_ptr<Image> getOutputPtr() override;

    int getNoise();
};


#endif //FILTERS_GAUSSIANNOISENODE_H
