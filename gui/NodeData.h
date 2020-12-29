//
// Created by noxin on 12/29/20.
//

#ifndef FILTERS_NODEDATA_H
#define FILTERS_NODEDATA_H

#include <QtCore/QString>


struct NodeDataType {
    QString id;
    QString name;
};

/// Class represents data transferred between nodes.
/// @param type is used for comparing the types
/// The actual data is stored in subtypes
class NodeData {
public:

    virtual ~NodeData() = default;

    virtual bool sameType(NodeData const &nodeData) const {
        return (this->type().id == nodeData.type().id);
    }

    /// Type for inner use
    virtual NodeDataType type() const = 0;
};

#endif //FILTERS_NODEDATA_H
