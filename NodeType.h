//
// Created by noxin on 10/27/20.
//

#ifndef FILTERS_NODETYPE_H
#define FILTERS_NODETYPE_H


enum class NodeType{
    NodeInput,
    GaussianBlurNode,
    EdgeDetectionNode,
    MedianNode,
    ColorGeneratorNode,
    NegativeNode,
    GaussianNoiseNode,
    CombineNode,
    BlackAndWhiteNode,
    NodeOutput
};

#endif //FILTERS_NODETYPE_H
