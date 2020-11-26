//
// Created by noxin on 10/27/20.
//

#ifndef FILTERS_NODE_H
#define FILTERS_NODE_H

#include <memory>
#include <vector>
#include "NodeType.h"
#include "processors/IProcessor.h"
#include "Image.h"
#include "Config.h"

class Node {
//temporary public should be private
public:
    std::unique_ptr<IProcessor> processor;
    std::shared_ptr<Image> preview;
    NodeType nodeType;
    std::shared_ptr<Image> outputPointer;
    Config config;
public:
    Node(NodeType nodeType);
    //temp default constructor
    Node();
    ~Node();
    void process();
    void addInput(std::shared_ptr<Node>);
    void addOutput(std::shared_ptr<Node>);
    int getInputNumber();
    void generatePreview();
};


#endif //FILTERS_NODE_H
