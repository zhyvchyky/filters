//
// Created by noxin on 12/29/20.
//

#ifndef FILTERS_CONNECTIONSTATE_H
#define FILTERS_CONNECTIONSTATE_H

#include "PortType.h"

class Node;

/// Stores currently draggind end.
/// Remembers last hovered Node.
class ConnectionState
{
public:

    ConnectionState(PortType port = PortType::None)
            : _requiredPort(port)
    {}

    ConnectionState(const ConnectionState&) = delete;
    ConnectionState operator=(const ConnectionState&) = delete;

    ~ConnectionState();

public:

    void setRequiredPort(PortType end)
    { _requiredPort = end; }

    PortType requiredPort() const
    { return _requiredPort; }

    bool requiresPort() const
    { return _requiredPort != PortType::None; }

    void setNoRequiredPort()
    { _requiredPort = PortType::None; }

public:

    void interactWithNode(Node* node);

    void setLastHoveredNode(Node* node);

    Node*
    lastHoveredNode() const
    { return _lastHoveredNode; }

    void resetLastHoveredNode();

private:

    PortType _requiredPort;

    Node* _lastHoveredNode{nullptr};
};

#endif //FILTERS_CONNECTIONSTATE_H
