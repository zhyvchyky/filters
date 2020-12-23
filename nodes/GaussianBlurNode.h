//
// Created by linups on 12/19/20.
//

#ifndef FILTERS_GAUSSIANBLURNODE_H
#define FILTERS_GAUSSIANBLURNODE_H
#include "ANode.h"
#include "utilities/applyVectorTransform.h"
#include "ISubject.h"
#include <cassert>



class GaussianBlurNode: public ANode, public ISubject<GaussianBlurNode> {

private:
    int N; //radius of blur must fall between 1 and 100



    std::shared_ptr<Image> applyTransform(const std::shared_ptr<Image>& img1);
    double* calcWeights();
    Pixel regulatePixel(Pixel pxl);
public:
    void process() override;

    void setRadius(int radius);

    int getRadius() const;
};


#endif //FILTERS_GAUSSIANBLURNODE_H
