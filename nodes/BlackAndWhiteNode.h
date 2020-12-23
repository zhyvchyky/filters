//
// Created by makstar on 01.12.2020.
//

#ifndef FILTERS_BLACKANDWHITENODE_H
#define FILTERS_BLACKANDWHITENODE_H

#include "ANode.h"
#include "ISubject.h"
#include <cassert>

class BlackAndWhiteNode: public ANode, public ISubject<BlackAndWhiteNode> {
private:


    std::shared_ptr<Image> applyTransform(const std::shared_ptr<Image>&);
public:
    void process() override;
    NodeType getNodeType() override;
};


#endif //FILTERS_BLACKANDWHITENODE_H
