//
// Created by noxin on 11/30/20.
//

#ifndef FILTERS_INODE_H
#define FILTERS_INODE_H

#include <memory>
#include <vector>
#include <variant>
#include "Image.h"

class INode {
public:
    virtual void process() = 0;

    virtual void setOutput(int index, std::shared_ptr<INode>) = 0;

    virtual void setInput(int index, std::shared_ptr<INode>) = 0;

    virtual std::shared_ptr<Image> getOutputPtr() = 0;
};


#endif //FILTERS_INODE_H
