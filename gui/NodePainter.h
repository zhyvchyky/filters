//
// Created by noxin on 12/29/20.
//

#ifndef FILTERS_NODEPAINTER_H
#define FILTERS_NODEPAINTER_H

#include <QtGui/QPainter>

class Node;
class NodeState;
class NodeGeometry;
class NodeGraphicsObject;
class NodeDataModel;
class FiltersItemEntry;
class FiltersScene;

class NodePainter {
public:

    NodePainter();

public:

    static
    void
    paint(QPainter *painter,
          Node &node,
          FiltersScene const &scene);

    static
    void
    drawNodeRect(QPainter *painter,
                 NodeGeometry const &geom,
                 NodeDataModel const *model,
                 NodeGraphicsObject const &graphicsObject);

    static
    void
    drawModelName(QPainter *painter,
                  NodeGeometry const &geom,
                  NodeState const &state,
                  NodeDataModel const *model);

    static
    void
    drawEntryLabels(QPainter *painter,
                    NodeGeometry const &geom,
                    NodeState const &state,
                    NodeDataModel const *model);

    static
    void
    drawConnectionPoints(QPainter *painter,
                         NodeGeometry const &geom,
                         NodeState const &state,
                         NodeDataModel const *model,
                         FiltersScene const &scene);

    static
    void
    drawFilledConnectionPoints(QPainter *painter,
                               NodeGeometry const &geom,
                               NodeState const &state,
                               NodeDataModel const *model);

    static
    void
    drawResizeRect(QPainter *painter,
                   NodeGeometry const &geom,
                   NodeDataModel const *model);

    static
    void
    drawValidationRect(QPainter *painter,
                       NodeGeometry const &geom,
                       NodeDataModel const *model,
                       NodeGraphicsObject const &graphicsObject);
};

#endif //FILTERS_NODEPAINTER_H
