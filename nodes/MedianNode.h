//
// Created by makstar on 06.12.2020.
//

#ifndef FILTERS_MEDIANNODE_H
#define FILTERS_MEDIANNODE_H

#include "INode.h"
#include <cassert>
#include <algorithm>

class MedianNode: public INode {
private:
    int N;//N must fall between 1 and 5

    std::vector<std::shared_ptr<INode>> inputs;
    std::vector<std::shared_ptr<INode>> outputs;
    std::shared_ptr<Image> outputPtr;

    std::shared_ptr<Image> applyTransform(const std::shared_ptr<Image>&);
    int getPositionMedian(std::vector<double> vec);

public:
    void process() override;

    void setOutput(int index, std::shared_ptr<INode>) override;

    void setInput(int index, std::shared_ptr<INode>) override;

    void setFields(std::vector<std::variant<int, std::string>>) override;

    std::shared_ptr<Image> getOutputPtr() override;

    std::vector<std::variant<int, std::string>> getFields() override;
};


#endif //FILTERS_MEDIANNODE_H
