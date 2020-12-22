//
// Created by noxin on 10/27/20.
//

#ifndef FILTERS_NODETYPE_H
#define FILTERS_NODETYPE_H

enum class NodeType{
    NodeInput,
    NodeOutput,
    GaussianBlurNode,
    EdgeDetectionNode,
    MedianNode,
    ColorGeneratorNode,
    NegativeNode,
    GaussianNoiseNode,
    CombineNode,
    BlackAndWhiteNode
};

#endif //FILTERS_NODETYPE_H
