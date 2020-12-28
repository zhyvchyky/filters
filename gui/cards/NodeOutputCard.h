//
// Created by makstsar on 26.12.2020.
//

#ifndef FILTERS_NODEOUTPUTCARD_H
#define FILTERS_NODEOUTPUTCARD_H

#include "nodes/NodeOutput.h"
#include "IObserver.h"

class NodeOutputCard: public IObserver<NodeOutput> {
private:
    std::string filepath;
public:
    std::string getFilePath();
    void notify(std::shared_ptr<NodeOutput>) override;
};


#endif //FILTERS_NODEOUTPUTCARD_H
