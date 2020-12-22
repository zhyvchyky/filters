//
// Created by linups on 12/19/20.
//

#ifndef FILTERS_GAUSSIANNOISENODE_H
#define FILTERS_GAUSSIANNOISENODE_H
#include "ANode.h"

class GaussianNoiseNode: public ANode {
private:
    int noise, height, width;



    std::shared_ptr<Image> genNormDist();

public:
    void process() override;

    void setNoise(int ns, int h, int w);

    std::tuple<int,int,int> getNoise();
};


#endif //FILTERS_GAUSSIANNOISENODE_H
