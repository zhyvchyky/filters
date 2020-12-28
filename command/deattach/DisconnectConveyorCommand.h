//
// Created by makstsar on 27.12.2020.
//

#ifndef FILTERS_DISCONNECTCONVEYORCOMMAND_H
#define FILTERS_DISCONNECTCONVEYORCOMMAND_H

#include "command/ICommand.h"
#include "ConveyorManager.h"
#include "gui/cards/ConveyorCard.h"

class DisconnectConveyorCommand: public ICommand {
private:
    std::shared_ptr<ConveyorManager> receiver;
    size_t conveyorId;
    std::shared_ptr<IObserver<Conveyor>> card;
public:
    explicit DisconnectConveyorCommand(std::shared_ptr<ConveyorManager>, size_t, std::shared_ptr<IObserver<Conveyor>>);
    bool execute() override;
};


#endif //FILTERS_DISCONNECTCONVEYORCOMMAND_H
