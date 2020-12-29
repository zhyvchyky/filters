//
// Created by noxin on 12/29/20.
//

#ifndef FILTERS_TEXTDATA_H
#define FILTERS_TEXTDATA_H

#include "gui/NodeData.h"

class TextData : public NodeData
{
public:

    TextData() {}

    TextData(QString const &text)
            : _text(text)
    {}

    NodeDataType type() const override
    { return NodeDataType {"text", "Text"}; }

    QString text() const { return _text; }

private:

    QString _text;
};


#endif //FILTERS_TEXTDATA_H
