//
// Created by makstsar on 26.12.2020.
//

#ifndef FILTERS_GAUSSIANNOISECARD_H
#define FILTERS_GAUSSIANNOISECARD_H

#include "nodes/GaussianNoiseNode.h"
#include "IObserver.h"

class GaussianNoiseCard: public IObserver<GaussianNoiseNode> {
private:
    int noise, height, width;
public:
    std::tuple<int,int,int> getNoise();
    void notify(std::shared_ptr<GaussianNoiseNode>) override;
};


#endif //FILTERS_GAUSSIANNOISECARD_H
