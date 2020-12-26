//
// Created by linups on 12/19/20.
//

#ifndef FILTERS_NEGATIVENODE_H
#define FILTERS_NEGATIVENODE_H
#include "ANode.h"
#include "ISubject.h"


class NegativeNode: public ANode, public ISubject<NegativeNode> {
private:
    std::shared_ptr<Image> applyTransform(std::shared_ptr<Image> img1);
    void process() override;

public:
    NodeType getNodeType() override;
};


#endif //FILTERS_NEGATIVENODE_H
