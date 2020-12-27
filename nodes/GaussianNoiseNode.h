//
// Created by linups on 12/19/20.
//

#ifndef FILTERS_GAUSSIANNOISENODE_H
#define FILTERS_GAUSSIANNOISENODE_H
#include "ANode.h"
#include "ISubject.h"

class GaussianNoiseNode: public ANode, public ISubject<GaussianNoiseNode> {
private:
    int noise, height, width;

    void setNoise(int ns, int h, int w);
    std::shared_ptr<Image> genNormDist();
    void process() override;

public:
    friend class SetGaussianNoiseCommand;

    std::tuple<int,int,int> getNoise();

    NodeType getNodeType() override;
};


#endif //FILTERS_GAUSSIANNOISENODE_H
