//
// Created by makstsar on 27.12.2020.
//

#ifndef FILTERS_ATTACHCONVEYORCOMMAND_H
#define FILTERS_ATTACHCONVEYORCOMMAND_H

#include "command/ICommand.h"
#include "ConveyorManager.h"

class AttachConveyorCommand: public ICommand {
private:
    std::shared_ptr<ConveyorManager> receiver;
    size_t conveyorId;
    std::shared_ptr<IConveyorObserver> card;
public:
    explicit AttachConveyorCommand(std::shared_ptr<ConveyorManager>, size_t, std::shared_ptr<IConveyorObserver>);
    bool execute() override;
};


#endif //FILTERS_ATTACHCONVEYORCOMMAND_H
