//
// Created by noxin on 12/29/20.
//

#ifndef FILTERS_TYPECONVERTER_H
#define FILTERS_TYPECONVERTER_H

#include "NodeData.h"
#include <memory>
#include <functional>

using SharedNodeData = std::shared_ptr<NodeData>;

// a function taking in NodeData and returning NodeData
using TypeConverter =
std::function<SharedNodeData(SharedNodeData)>;

// data-type-in, data-type-out
using TypeConverterId =
std::pair<NodeDataType, NodeDataType>;

#endif //FILTERS_TYPECONVERTER_H
