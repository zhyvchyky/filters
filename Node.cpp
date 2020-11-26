//
// Created by noxin on 10/27/20.
//

#include <iostream>
#include "Node.h"

Node::Node(NodeType nodeType) {
    nodeType = nodeType;
    std::cout << "Node object created" << std::endl;
//    switch (nodeType) {
//
//        case InputNode:
//            this->processor = std::make_unique<ImageSourceProcessor>();
//            break;
//        case OutputNode:
//            this->processor = std::make_unique<ImageOutputProcessor>();
//            break;
//        case CombineNode:
//            this->processor = std::make_unique<CombineProcessor>();
//            break;
//        case BlurNode:
//            this->processor = std::make_unique<BlurProcessor>();
//            break;
//        case MotionBlurNode:
//            this->processor = std::make_unique<MotionBlurProcessor>();
//            break;
//        case SharpeningNode:
//            this->processor = std::make_unique<SharpeningProcessor>();
//            break;
//        case BlackAndWhiteNode:
//            this->processor = std::make_unique<BlackAndWhiteProcessor>();
//            break;
//        case ErosionNode:
//            this->processor = std::make_unique<ErosionProcessor>();
//            break;
//    }
}

Node::~Node() {
    std::cout << "Node object deleted" << std::endl;
}

Node::Node() {

}
