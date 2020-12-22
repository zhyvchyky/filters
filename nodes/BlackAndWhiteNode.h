//
// Created by makstar on 01.12.2020.
//

#ifndef FILTERS_BLACKANDWHITENODE_H
#define FILTERS_BLACKANDWHITENODE_H

#include "ANode.h"
#include <cassert>

class BlackAndWhiteNode: public ANode {
private:


    std::shared_ptr<Image> applyTransform(const std::shared_ptr<Image>&);
public:
    void process() override;
};


#endif //FILTERS_BLACKANDWHITENODE_H
