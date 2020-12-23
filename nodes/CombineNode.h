//
// Created by linups on 12/19/20.
//

#ifndef FILTERS_COMBINENODE_H
#define FILTERS_COMBINENODE_H
#include "ANode.h"


class CombineNode: public ANode {
private:


    std::shared_ptr<Image> combine();

public:
    void process() override;

    void setInput(std::shared_ptr<ANode> node) override;

    void resetInput(std::shared_ptr<ANode> node) override;
};


#endif //FILTERS_COMBINENODE_H
