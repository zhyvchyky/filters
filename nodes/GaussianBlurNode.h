//
// Created by linups on 12/19/20.
//

#ifndef FILTERS_GAUSSIANBLURNODE_H
#define FILTERS_GAUSSIANBLURNODE_H
#include "ANode.h"
#include "utilities/applyVectorTransform.h"
#include <cassert>


class GaussianBlurNode: public ANode {
private:
    int N; //radius of blur must fall between 1 and 100



    std::shared_ptr<Image> applyTransform(const std::shared_ptr<Image>& img1);
    double* calcWeights();
public:
    void process() override;

    void setRadius(int radius);

    int getRadius() const;
};


#endif //FILTERS_GAUSSIANBLURNODE_H
