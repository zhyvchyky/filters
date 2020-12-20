//
// Created by linups on 12/19/20.
//

#ifndef FILTERS_GAUSSIANNOISENODE_H
#define FILTERS_GAUSSIANNOISENODE_H
#include "INode.h"

class GaussianNoiseNode: public INode {
private:
    int noise, height, width;

    std::vector<std::shared_ptr<INode>> inputs;
    std::vector<std::shared_ptr<INode>> outputs;
    std::shared_ptr<Image> outputPtr;

    std::shared_ptr<Image> genNormDist();

public:
    void process() override;

    void setOutput(int index, std::shared_ptr<INode>) override;

    void setInput(int index, std::shared_ptr<INode>) override;

    void setNoise(int ns, int h, int w);

    std::shared_ptr<Image> getOutputPtr() override;

    std::tuple<int,int,int> getNoise();
};


#endif //FILTERS_GAUSSIANNOISENODE_H
