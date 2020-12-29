//
// Created by noxin on 12/27/20.
//

#include "FiltersScene.h"
#include <utility>

#include <QtWidgets/QGraphicsSceneMoveEvent>
#include <QtWidgets/QFileDialog>
#include <QtCore/QByteArray>
#include <QtCore/QBuffer>
#include <QtCore/QDataStream>
#include <QtCore/QFile>

#include "ConnectionGraphicsObject.h"
#include "Node.h"

//FiltersScene::FiltersScene(std::shared_ptr<DataModelRegistry> registry, QObject * parent): QGraphicsScene(parent), _registry(std::move(registry))
//{
//    setItemIndexMethod(QGraphicsScene::NoIndex);
//
//    // This connection should come first
//    connect(this, &FiltersScene::connectionCreated, this, &FiltersScene::setupConnectionSignals);
//    connect(this, &FiltersScene::connectionCreated, this, &FiltersScene::sendConnectionCreatedToNodes);
//    connect(this, &FiltersScene::connectionDeleted, this, &FiltersScene::sendConnectionDeletedToNodes);
//}

//FiltersScene::
//FiltersScene(QObject * parent)
//        : FiltersScene(std::make_shared<DataModelRegistry>(),
//                    parent)
//{}

FiltersScene::FiltersScene(QObject * parent): QGraphicsScene(parent){
}


FiltersScene::~FiltersScene()
{
    clearScene();
}


//------------------------------------------------------------------------------

std::shared_ptr<Connection>
FiltersScene::
createConnection(PortType connectedPort,
                 Node& node,
                 PortIndex portIndex)
{
    auto connection = std::make_shared<Connection>(connectedPort, node, portIndex);

    auto cgo = std::make_unique<ConnectionGraphicsObject>(*this, *connection);

    // after this function connection points are set to node port
    connection->setGraphicsObject(std::move(cgo));

    _connections[connection->id()] = connection;

    // Note: this connection isn't truly created yet. It's only partially created.
    // Thus, don't send the connectionCreated(...) signal.

    connect(connection.get(),
            &Connection::connectionCompleted,
            this,
            [this](Connection const& c) {
                connectionCreated(c);
            });

    return connection;
}


std::shared_ptr<Connection>
FiltersScene::
createConnection(Node& nodeIn,
                 PortIndex portIndexIn,
                 Node& nodeOut,
                 PortIndex portIndexOut,
                 TypeConverter const &converter)
{
    auto connection =
            std::make_shared<Connection>(nodeIn,
                                         portIndexIn,
                                         nodeOut,
                                         portIndexOut,
                                         converter);

    auto cgo = std::make_unique<ConnectionGraphicsObject>(*this, *connection);

    nodeIn.nodeState().setConnection(PortType::In, portIndexIn, *connection);
    nodeOut.nodeState().setConnection(PortType::Out, portIndexOut, *connection);

    // after this function connection points are set to node port
    connection->setGraphicsObject(std::move(cgo));

    // trigger data propagation
    nodeOut.onDataUpdated(portIndexOut);

    _connections[connection->id()] = connection;

    connectionCreated(*connection);

    return connection;
}


std::shared_ptr<Connection>
FiltersScene::
restoreConnection(QJsonObject const &connectionJson)
{
    QUuid nodeInId  = QUuid(connectionJson["in_id"].toString());
    QUuid nodeOutId = QUuid(connectionJson["out_id"].toString());

    PortIndex portIndexIn  = connectionJson["in_index"].toInt();
    PortIndex portIndexOut = connectionJson["out_index"].toInt();

    auto nodeIn  = _nodes[nodeInId].get();
    auto nodeOut = _nodes[nodeOutId].get();

    auto getConverter = [&]()
    {
        QJsonValue converterVal = connectionJson["converter"];

        if (!converterVal.isUndefined())
        {
            QJsonObject converterJson = converterVal.toObject();

            NodeDataType inType { converterJson["in"].toObject()["id"].toString(),
                                  converterJson["in"].toObject()["name"].toString() };

            NodeDataType outType { converterJson["out"].toObject()["id"].toString(),
                                   converterJson["out"].toObject()["name"].toString() };

            auto converter  =
                    registry().getTypeConverter(outType, inType);

            if (converter)
                return converter;
        }

        return TypeConverter{};
    };

    std::shared_ptr<Connection> connection =
            createConnection(*nodeIn, portIndexIn,
                             *nodeOut, portIndexOut,
                             getConverter());

    // Note: the connectionCreated(...) signal has already been sent
    // by createConnection(...)

    return connection;
}


void
FiltersScene::
deleteConnection(Connection& connection)
{
    auto it = _connections.find(connection.id());
    if (it != _connections.end()) {
        connection.removeFromNodes();
        _connections.erase(it);
    }
}


Node&
FiltersScene::
createNode(std::unique_ptr<NodeDataModel> && dataModel)
{
    auto node = detail::make_unique<Node>(std::move(dataModel));
    auto ngo  = detail::make_unique<NodeGraphicsObject>(*this, *node);

    node->setGraphicsObject(std::move(ngo));

    auto nodePtr = node.get();
    _nodes[node->id()] = std::move(node);

    nodeCreated(*nodePtr);
    return *nodePtr;
}


Node&
FiltersScene::
restoreNode(QJsonObject const& nodeJson)
{
    QString modelName = nodeJson["model"].toObject()["name"].toString();

    auto dataModel = registry().create(modelName);

    if (!dataModel)
        throw std::logic_error(std::string("No registered model with name ") +
                               modelName.toLocal8Bit().data());

    auto node = detail::make_unique<Node>(std::move(dataModel));
    auto ngo  = detail::make_unique<NodeGraphicsObject>(*this, *node);
    node->setGraphicsObject(std::move(ngo));

    node->restore(nodeJson);

    auto nodePtr = node.get();
    _nodes[node->id()] = std::move(node);

    nodePlaced(*nodePtr);
    nodeCreated(*nodePtr);
    return *nodePtr;
}


void
FiltersScene::
removeNode(Node& node)
{
    // call signal
    nodeDeleted(node);

    for(auto portType: {PortType::In,PortType::Out})
    {
        auto nodeState = node.nodeState();
        auto const & nodeEntries = nodeState.getEntries(portType);

        for (auto &connections : nodeEntries)
        {
            for (auto const &pair : connections)
                deleteConnection(*pair.second);
        }
    }

    _nodes.erase(node.id());
}


DataModelRegistry&
FiltersScene::
registry() const
{
    return *_registry;
}


void
FiltersScene::
setRegistry(std::shared_ptr<DataModelRegistry> registry)
{
    _registry = std::move(registry);
}


void
FiltersScene::
iterateOverNodes(std::function<void(Node*)> const & visitor)
{
    for (const auto& _node : _nodes)
    {
        visitor(_node.second.get());
    }
}


void
FiltersScene::
iterateOverNodeData(std::function<void(NodeDataModel*)> const & visitor)
{
    for (const auto& _node : _nodes)
    {
        visitor(_node.second->nodeDataModel());
    }
}


void
FiltersScene::
iterateOverNodeDataDependentOrder(std::function<void(NodeDataModel*)> const & visitor)
{
    std::set<QUuid> visitedNodesSet;

    //A leaf node is a node with no input ports, or all possible input ports empty
    auto isNodeLeaf =
            [](Node const &node, NodeDataModel const &model)
            {
                for (unsigned int i = 0; i < model.nPorts(PortType::In); ++i)
                {
                    auto connections = node.nodeState().connections(PortType::In, i);
                    if (!connections.empty())
                    {
                        return false;
                    }
                }

                return true;
            };

    //Iterate over "leaf" nodes
    for (auto const &_node : _nodes)
    {
        auto const &node = _node.second;
        auto model       = node->nodeDataModel();

        if (isNodeLeaf(*node, *model))
        {
            visitor(model);
            visitedNodesSet.insert(node->id());
        }
    }

    auto areNodeInputsVisitedBefore =
            [&](Node const &node, NodeDataModel const &model)
            {
                for (size_t i = 0; i < model.nPorts(PortType::In); ++i)
                {
                    auto connections = node.nodeState().connections(PortType::In, i);

                    for (auto& conn : connections)
                    {
                        if (visitedNodesSet.find(conn.second->getNode(PortType::Out)->id()) == visitedNodesSet.end())
                        {
                            return false;
                        }
                    }
                }

                return true;
            };

    //Iterate over dependent nodes
    while (_nodes.size() != visitedNodesSet.size())
    {
        for (auto const &_node : _nodes)
        {
            auto const &node = _node.second;
            if (visitedNodesSet.find(node->id()) != visitedNodesSet.end())
                continue;

            auto model = node->nodeDataModel();

            if (areNodeInputsVisitedBefore(*node, *model))
            {
                visitor(model);
                visitedNodesSet.insert(node->id());
            }
        }
    }
}


QPointF
FiltersScene::
getNodePosition(const Node& node) const
{
    return node.nodeGraphicsObject().pos();
}


void
FiltersScene::
setNodePosition(Node& node, const QPointF& pos) const
{
    node.nodeGraphicsObject().setPos(pos);
    node.nodeGraphicsObject().moveConnections();
}


QSizeF
FiltersScene::
getNodeSize(const Node& node) const
{
    return QSizeF(node.nodeGeometry().width(), node.nodeGeometry().height());
}


std::unordered_map<QUuid, std::unique_ptr<Node> > const &
FiltersScene::
nodes() const
{
    return _nodes;
}


std::unordered_map<QUuid, std::shared_ptr<Connection> > const &
FiltersScene::
connections() const
{
    return _connections;
}


std::vector<Node*>
FiltersScene::
allNodes() const
{
    std::vector<Node*> nodes;

    std::transform(_nodes.begin(),
                   _nodes.end(),
                   std::back_inserter(nodes),
                   [](std::pair<QUuid const, std::unique_ptr<Node>> const & p) { return p.second.get(); });

    return nodes;
}


std::vector<Node*>
FiltersScene::
selectedNodes() const
{
    QList<QGraphicsItem*> graphicsItems = selectedItems();

    std::vector<Node*> ret;
    ret.reserve(graphicsItems.size());

    for (QGraphicsItem* item : graphicsItems)
    {
        auto ngo = qgraphicsitem_cast<NodeGraphicsObject*>(item);

        if (ngo != nullptr)
        {
            ret.push_back(&ngo->node());
        }
    }

    return ret;
}


//------------------------------------------------------------------------------

void
FiltersScene::
clearScene()
{
    //Manual node cleanup. Simply clearing the holding datastructures doesn't work, the code crashes when
    // there are both nodes and connections in the scene. (The data propagation internal logic tries to propagate
    // data through already freed connections.)
    while (_connections.size() > 0)
    {
        deleteConnection( *_connections.begin()->second );
    }

    while (_nodes.size() > 0)
    {
        removeNode( *_nodes.begin()->second );
    }
}


void
FiltersScene::
setupConnectionSignals(Connection const& c)
{
    connect(&c,
            &Connection::connectionMadeIncomplete,
            this,
            &FiltersScene::connectionDeleted,
            Qt::UniqueConnection);
}


void
FiltersScene::
sendConnectionCreatedToNodes(Connection const& c)
{
    Node* from = c.getNode(PortType::Out);
    Node* to   = c.getNode(PortType::In);

    Q_ASSERT(from != nullptr);
    Q_ASSERT(to != nullptr);

    from->nodeDataModel()->outputConnectionCreated(c);
    to->nodeDataModel()->inputConnectionCreated(c);
}


void
FiltersScene::
sendConnectionDeletedToNodes(Connection const& c)
{
    Node* from = c.getNode(PortType::Out);
    Node* to   = c.getNode(PortType::In);

    Q_ASSERT(from != nullptr);
    Q_ASSERT(to != nullptr);

    from->nodeDataModel()->outputConnectionDeleted(c);
    to->nodeDataModel()->inputConnectionDeleted(c);
}


//------------------------------------------------------------------------------
namespace QtNodes
{

    Node*
    locateNodeAt(QPointF scenePoint, FiltersScene &scene,
                 QTransform const & viewTransform)
    {
        // items under cursor
        QList<QGraphicsItem*> items =
                scene.items(scenePoint,
                            Qt::IntersectsItemShape,
                            Qt::DescendingOrder,
                            viewTransform);

        //// items convertable to NodeGraphicsObject
        std::vector<QGraphicsItem*> filteredItems;

        std::copy_if(items.begin(),
                     items.end(),
                     std::back_inserter(filteredItems),
                     [] (QGraphicsItem * item)
                     {
                         return (dynamic_cast<NodeGraphicsObject*>(item) != nullptr);
                     });

        Node* resultNode = nullptr;

        if (!filteredItems.empty())
        {
            QGraphicsItem* graphicsItem = filteredItems.front();
            auto ngo = dynamic_cast<NodeGraphicsObject*>(graphicsItem);

            resultNode = &ngo->node();
        }

        return resultNode;
    }
}