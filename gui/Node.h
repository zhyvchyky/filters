//
// Created by noxin on 12/29/20.
//

#ifndef FILTERS_NODE_H
#define FILTERS_NODE_H


#include <QtCore/QObject>
#include <QtCore/QUuid>

#include <QtCore/QJsonObject>

#include "PortType.h"

#include "NodeState.h"
#include "NodeGeometry.h"
#include "NodeData.h"
#include "NodeGraphicsObject.h"
#include "ConnectionGraphicsObject.h"
#include <memory>


class Connection;

class ConnectionState;

class NodeGraphicsObject;

class NodeDataModel;

class Node : public QObject {
Q_OBJECT

public:

/// NodeDataModel should be an rvalue and is moved into the Node
    Node(std::unique_ptr<NodeDataModel> &&dataModel);

    virtual ~Node();


public:

    QUuid id() const;

    void reactToPossibleConnection(PortType,
                                   NodeDataType const &,
                                   QPointF const &scenePoint);

    void resetReactionToConnection();

public:

    NodeGraphicsObject const &nodeGraphicsObject() const;

    NodeGraphicsObject &nodeGraphicsObject();

    void setGraphicsObject(std::unique_ptr<NodeGraphicsObject> &&graphics);

    NodeGeometry &nodeGeometry();

    NodeGeometry const &nodeGeometry() const;

    NodeState const &nodeState() const;

    NodeState &nodeState();

    NodeDataModel *nodeDataModel() const;

public Q_SLOTS: // data propagation

/// Propagates incoming data to the underlying model.
    void propagateData(std::shared_ptr<NodeData> nodeData,
                  PortIndex inPortIndex) const;

/// Fetches data from model's OUT #index port
/// and propagates it to the connection
    void onDataUpdated(PortIndex index);

/// update the graphic part if the size of the embeddedwidget changes
    void onNodeSizeUpdated();

private:

// addressing

    QUuid _uid;

// data

    std::unique_ptr<NodeDataModel> _nodeDataModel;

    NodeState _nodeState;

// painting

    NodeGeometry _nodeGeometry;

    std::unique_ptr<NodeGraphicsObject> _nodeGraphicsObject;
};


#endif //FILTERS_NODE_H
