//
// Created by makstsar on 26.12.2020.
//

#ifndef FILTERS_AATTACHCOMMAND_H
#define FILTERS_AATTACHCOMMAND_H

#include "command/ICommand.h"
#include "nodes/ANode.h"
#include "ConveyorManager.h"
#include <memory>

template <class T>
class AAttachCommand: public ICommand{
protected:
    std::shared_ptr<ConveyorManager> receiver;
    size_t nodeId;
    size_t conveyorId;
    std::shared_ptr<T> card;
    AAttachCommand(std::shared_ptr<ConveyorManager> rec, size_t cI, size_t nI, std::shared_ptr<T> c)
        : receiver(rec), conveyorId(cI), nodeId(nI), card(c){};
public:
    virtual bool execute() = 0;
};



#endif //FILTERS_AATTACHCOMMAND_H
