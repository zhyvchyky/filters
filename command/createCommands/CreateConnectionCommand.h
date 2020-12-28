//
// Created by makstar on 23.12.2020.
//

#ifndef FILTERS_CREATECONNECTIONCOMMAND_H
#define FILTERS_CREATECONNECTIONCOMMAND_H

#include "command/ICommand.h"
#include "ConveyorManager.h"

class CreateConnectionCommand: public ICommand {
private:
    std::shared_ptr<ConveyorManager> receiver;
    size_t conveyorId, inputNodeId, outputNodeId;
public:
    explicit CreateConnectionCommand(std::shared_ptr<ConveyorManager> rec, size_t conveyorId, size_t inputNodeId, size_t outputNodeId);
    bool execute() override;
};


#endif //FILTERS_CREATECONNECTIONCOMMAND_H
