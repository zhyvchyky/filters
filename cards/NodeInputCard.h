//
// Created by noxin on 12/23/20.
//

#ifndef FILTERS_NODEINPUTCARD_H
#define FILTERS_NODEINPUTCARD_H

#include "IObserver.h"
#include "nodes/NodeInput.h"


class NodeInputCard: public IObserver<NodeInput> {
private:
    std::string filepath;
public:
    std::string getFilePath();
    void notify(std::shared_ptr<NodeInput> node) override;
};


#endif //FILTERS_NODEINPUTCARD_H
