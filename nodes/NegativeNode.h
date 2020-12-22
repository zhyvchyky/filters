//
// Created by linups on 12/19/20.
//

#ifndef FILTERS_NEGATIVENODE_H
#define FILTERS_NEGATIVENODE_H
#include "ANode.h"


class NegativeNode: public ANode {
private:


    std::shared_ptr<Image> applyTransform(std::shared_ptr<Image> img1);

public:
    void process() override;
};


#endif //FILTERS_NEGATIVENODE_H
