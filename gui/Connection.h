//
// Created by noxin on 12/29/20.
//

#ifndef FILTERS_CONNECTION_H
#define FILTERS_CONNECTION_H

#include <QtCore/QObject>
#include <QUuid>
#include <memory>
#include "PortType.h"
#include "NodeData.h"
#include "ConnectionState.h"
#include "ConnectionGeometry.h"
#include "TypeConverter.h"

class Node;

class NodeData;

class ConnectionGraphicsObject;

///
class Connection: public QObject{

Q_OBJECT

public:

/// New Connection is attached to the port of the given Node.
/// The port has parameters (portType, portIndex).
/// The opposite connection end will require anothre port.
    Connection(PortType
               portType,
               Node &node,
               PortIndex
               portIndex);

    Connection(Node &nodeIn,
               PortIndex portIndexIn,
               Node
               &nodeOut,
               PortIndex portIndexOut,
               TypeConverter
               converter =
               TypeConverter{}
    );

    Connection(const Connection &) = delete;

    Connection operator=(const Connection &) = delete;

    ~Connection();

public:

    QUuid
    id() const;

/// Remembers the end being dragged.
/// Invalidates Node address.
/// Grabs mouse.
    void
    setRequiredPort(PortType
                    portType);

    PortType
    requiredPort() const;

    void
    setGraphicsObject(std::unique_ptr <ConnectionGraphicsObject> &&graphics);

/// Assigns a node to the required port.
/// It is assumed that there is a required port, no extra checks
    void
    setNodeToPort(Node &node,
                  PortType
                  portType,
                  PortIndex portIndex
    );

    void
    removeFromNodes() const;

public:

    ConnectionGraphicsObject &
    getConnectionGraphicsObject() const;

    ConnectionState const &
    connectionState() const;

    ConnectionState &
    connectionState();

    ConnectionGeometry &
    connectionGeometry();

    ConnectionGeometry const &
    connectionGeometry() const;

    Node *
    getNode(PortType
            portType) const;

    Node *&
    getNode(PortType
            portType);

    PortIndex
    getPortIndex(PortType
                 portType) const;

    void
    clearNode(PortType
              portType);

    NodeDataType
    dataType(PortType
             portType) const;

    void
    setTypeConverter(TypeConverter
                     converter);

    bool
    complete() const;

public: // data propagation

    void
    propagateData(std::shared_ptr <NodeData> nodeData) const;

    void
    propagateEmptyData() const;

Q_SIGNALS:

    void
    connectionCompleted(Connection
                        const &) const;

    void
    connectionMadeIncomplete(Connection const &) const;

private:

    QUuid _uid;

private:

    Node *_outNode = nullptr;
    Node *_inNode = nullptr;

    PortIndex _outPortIndex;
    PortIndex _inPortIndex;

private:

    ConnectionState _connectionState;
    ConnectionGeometry _connectionGeometry;

    std::unique_ptr <ConnectionGraphicsObject> _connectionGraphicsObject;

    TypeConverter _converter;

Q_SIGNALS:

    void
    updated(Connection & conn)
    const;
};

#endif //FILTERS_CONNECTION_H
