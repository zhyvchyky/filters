//
// Created by makstar on 23.12.2020.
//

#ifndef FILTERS_DELETECONNECTIONCOMMAND_H
#define FILTERS_DELETECONNECTIONCOMMAND_H

#include "command/ICommand.h"
#include "ConveyorManager.h"

class DeleteConnectionCommand : public ICommand {
private:
    std::shared_ptr<ConveyorManager> receiver;
    size_t conveyorId, inputNodeId, outputNodeId;
public:
    explicit DeleteConnectionCommand(std::shared_ptr<ConveyorManager> rec, size_t ConveyorId, size_t inputNodeId, size_t outputNodeId);
    bool execute() override;
};


#endif //FILTERS_DELETECONNECTIONCOMMAND_H
