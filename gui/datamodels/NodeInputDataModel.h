//
// Created by noxin on 12/29/20.
//

#ifndef FILTERS_NODEINPUTDATAMODEL_H
#define FILTERS_NODEINPUTDATAMODEL_H


#include <QLabel>
#include "gui/NodeDataModel.h"
#include "TextData.h"

class NodeInputDataModel : NodeDataModel {
Q_OBJECT
public:
    NodeInputDataModel();

    virtual
    ~NodeInputDataModel() {}

public:

    QString
    caption() const override { return QString("Input file"); }

    bool
    captionVisible() const override { return false; }

    static QString
    Name() { return QString("NodeInputDataModel"); }

    QString
    name() const override { return NodeInputDataModel::Name(); }

public:

    unsigned int
    nPorts(PortType portType) const override;

    NodeDataType
    dataType(PortType portType, PortIndex portIndex) const override;

    std::shared_ptr<NodeData>
    outData(PortIndex port) override;

    void
    setInData(std::shared_ptr<NodeData> data, int) override {
        auto textData = std::dynamic_pointer_cast<TextData>(data);

        if (textData) {
            _label->setText(textData->text());
        } else {
            _label->clear();
        }

        _label->adjustSize();
    }

    QWidget *
    embeddedWidget() override { return _label; }

private:

    QLabel *_label;
};


#endif //FILTERS_NODEINPUTDATAMODEL_H
