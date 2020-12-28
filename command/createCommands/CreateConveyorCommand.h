//
// Created by noxin on 12/23/20.
//

#ifndef FILTERS_CREATECONVEYORCOMMAND_H
#define FILTERS_CREATECONVEYORCOMMAND_H

#include "command/ICommand.h"
#include "ConveyorManager.h"


class CreateConveyorCommand: public ICommand {
    std::shared_ptr<ConveyorManager> receiver;

public:
    explicit CreateConveyorCommand(std::shared_ptr<ConveyorManager>);
    bool execute() override;
};


#endif //FILTERS_CREATECONVEYORCOMMAND_H
