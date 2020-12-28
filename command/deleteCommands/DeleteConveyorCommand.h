//
// Created by makstar on 23.12.2020.
//

#ifndef FILTERS_DELETECONVEYORCOMMAND_H
#define FILTERS_DELETECONVEYORCOMMAND_H

#include "command/ICommand.h"
#include "ConveyorManager.h"

class DeleteConveyorCommand: public ICommand {
    std::shared_ptr<ConveyorManager> receiver;
    size_t conveyorId;
public:
    explicit DeleteConveyorCommand(std::shared_ptr<ConveyorManager> rec, size_t conveyorId);
    bool execute() override;
};


#endif //FILTERS_DELETECONVEYORCOMMAND_H
