//
// Created by noxin on 10/27/20.
//

#ifndef FILTERS_NODETYPE_H
#define FILTERS_NODETYPE_H
#include "nodes/NodeInput.h"
#include "nodes/NodeOutput.h"
#include "nodes/EdgeDetectionNode.h"
#include "nodes/BlackAndWhiteNode.h"
#include "nodes/GaussianBlurNode.h"
#include "nodes/NegativeNode.h"
#include "nodes/MedianNode.h"
#include "nodes/ColorGeneratorNode.h"
#include "nodes/CombineNode.h"
#include "nodes/GaussianNoiseNode.h"

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
