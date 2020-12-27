//
// Created by makstsar on 26.12.2020.
//

#ifndef FILTERS_ACONNECTCOMMAND_H
#define FILTERS_ACONNECTCOMMAND_H

#include "ICommand.h"
#include "nodes/ANode.h"
#include "ConveyorManager.h"
#include <memory>

template <class T>
class AConnectCommand: public ICommand{
protected:
    std::shared_ptr<ConveyorManager> receiver;
    size_t nodeId;
    size_t conveyorId;
    std::shared_ptr<T> card;
    AConnectCommand(std::shared_ptr<ConveyorManager> rec, size_t cI, size_t nI, std::shared_ptr<T> c)
        : receiver(rec), conveyorId(cI), nodeId(nI), card(c){};
public:
    virtual bool execute() = 0;
};



#endif //FILTERS_ACONNECTCOMMAND_H
