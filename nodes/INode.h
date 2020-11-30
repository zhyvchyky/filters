//
// Created by noxin on 11/30/20.
//

#ifndef FILTERS_INODE_H
#define FILTERS_INODE_H

#include <memory>
#include <vector>
#include <variant>

class INode {
    virtual void process() = 0;
    virtual void setOutput(int index, std::shared_ptr<INode>) = 0;
    virtual void setInput(int index, std::shared_ptr<INode>) = 0;
    virtual std::vector<std::variant<int, std::string>> getFields() = 0;
    virtual void setFields(std::vector<std::variant<int, std::string>>) = 0;
};


#endif //FILTERS_INODE_H
