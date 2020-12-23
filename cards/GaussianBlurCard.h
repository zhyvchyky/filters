//
// Created by linups on 12/23/20.
//

#ifndef FILTERS_GAUSSIANBLURCARD_H
#define FILTERS_GAUSSIANBLURCARD_H

#include "nodes/GaussianBlurNode.h"
#include "IObserver.h"

class GaussianBlurCard: public IObserver<GaussianBlurNode> {
private:
    int radius;
public:
    int getRadius();
    void notify(std::shared_ptr<GaussianBlurNode> node) override;
};


#endif //FILTERS_GAUSSIANBLURCARD_H
