//
// Created by linups on 12/19/20.
//

#ifndef FILTERS_COMBINENODE_H
#define FILTERS_COMBINENODE_H
#include "ANode.h"
#include "ISubject.h"


class CombineNode: public ANode, public ISubject<CombineNode> {
private:


    std::shared_ptr<Image> combine();

public:
    void process() override;
    NodeType getNodeType() override;

    void setInput(std::shared_ptr<ANode> node) override;

    void resetInput(std::shared_ptr<ANode> node) override;
};


#endif //FILTERS_COMBINENODE_H
