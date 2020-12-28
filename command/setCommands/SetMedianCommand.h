//
// Created by linups on 12/25/20.
//

#ifndef FILTERS_SETMEDIANCOMMAND_H
#define FILTERS_SETMEDIANCOMMAND_H

#include "command/ICommand.h"
#include "ConveyorManager.h"

class SetMedianCommand: public ICommand {
private:
    std::shared_ptr<ConveyorManager> receiver;
    size_t conveyorId, nodeId;
    int median;
public:
    SetMedianCommand(std::shared_ptr<ConveyorManager> rec, size_t conveyorId, size_t nodeId, int median);
    bool execute() override;
};


#endif //FILTERS_SETMEDIANCOMMAND_H
