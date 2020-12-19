//
// Created by linups on 12/19/20.
//

#ifndef FILTERS_GAUSSIANBLURNODE_H
#define FILTERS_GAUSSIANBLURNODE_H
#include "INode.h"
#include "utilities/applyVectorTransform.h"
#include <cassert>


class GaussianBlurNode: public INode {
private:
    int N; //radius of blur must fall between 1 and 100

    std::vector<std::shared_ptr<INode>> inputs;
    std::vector<std::shared_ptr<INode>> outputs;
    std::shared_ptr<Image> outputPtr;

    std::shared_ptr<Image> applyTransform(const std::shared_ptr<Image>& img1);
    double* calcWeights();
public:
    void process() override;

    void setOutput(int index, std::shared_ptr<INode>) override;

    void setInput(int index, std::shared_ptr<INode>) override;

    void setRadius(int radius);

    std::shared_ptr<Image> getOutputPtr() override;

    int getRadius() const;
};


#endif //FILTERS_GAUSSIANBLURNODE_H
