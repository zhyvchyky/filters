//
// Created by makstar on 23.12.2020.
//

#ifndef FILTERS_PROCESSCOMMAND_H
#define FILTERS_PROCESSCOMMAND_H

#include "ICommand.h"
#include "NodeType.h"
#include "ConveyorManager.h"

class ProcessCommand: public ICommand{
private:
    size_t conveyorId;
    std::shared_ptr<ConveyorManager> receiver;
public:
    ProcessCommand(size_t conveyorId, std::shared_ptr<ConveyorManager> rec);
    bool execute() override;
};


#endif //FILTERS_PROCESSCOMMAND_H
