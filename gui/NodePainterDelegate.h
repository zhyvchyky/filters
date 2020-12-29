//
// Created by noxin on 12/29/20.
//

#ifndef FILTERS_NODEPAINTERDELEGATE_H
#define FILTERS_NODEPAINTERDELEGATE_H

#include "NodeGeometry.h"
#include "NodeDataModel.h"
#include <QPainter>
class NodePainterDelegate {

public:

    virtual
    ~NodePainterDelegate() = default;

    virtual void
    paint(QPainter *painter,
          NodeGeometry const &geom,
          NodeDataModel const *model) = 0;
};

#endif //FILTERS_NODEPAINTERDELEGATE_H
