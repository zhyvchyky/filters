//
// Created by makstar on 23.12.2020.
//

#ifndef FILTERS_DELETENODECOMMAND_H
#define FILTERS_DELETENODECOMMAND_H

#include "command/ICommand.h"
#include "NodeType.h"
#include "ConveyorManager.h"

class DeleteNodeCommand: public ICommand{
private:
    size_t nodeId;
    size_t conveyorId;
    std::shared_ptr<ConveyorManager> receiver;
public:
    DeleteNodeCommand(size_t nodeId, size_t conveyorId, std::shared_ptr<ConveyorManager> rec);
    bool execute() override;
};


#endif //FILTERS_DELETENODECOMMAND_H
