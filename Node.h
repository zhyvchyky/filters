//
// Created by noxin on 10/27/20.
//

#ifndef FILTERS_NODE_H
#define FILTERS_NODE_H

#include <memory>
#include <vector>
#include "NodeType.h"
#include "IProcessor.h"
#include "Image.h"

class Node {

private:
    std::vector<std::shared_ptr<Node>> inputs;
    std::vector<std::shared_ptr<Node>> outputs;
    std::unique_ptr<IProcessor> processor;
    std::shared_ptr<Image> preview;
    NodeType nodeType;
    std::shared_ptr<Image> outputPointer;
public:
    Node(NodeType nodeType);
    ~Node();
    void process();
    void addInput(std::shared_ptr<Node>);
    void addOutput(std::shared_ptr<Node>);
    int getInputNumber();
    void generatePreview();
};


#endif //FILTERS_NODE_H
